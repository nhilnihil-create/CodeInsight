#include <iostream>

using namespace std;
const int N=1e6+10;
int a[N];
int c0,c1,c2;
int c[100][100];
int C(int n,int m)
{
    // if(n<m)return 1;
    return c[n][m];
}
int lucas(int n,int m)
{
    if(n<2&&m<2){
        return C(n,m)%2;
    }else{
        return C(n%2,m%2)*lucas(n/2,m/2)%2;
    }
}
int main()
{
    int n;
    cin>>n;
    c[0][0]=1;
    for(int i=1;i<=2;i++)
    {
        for(int j=0;j<=i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    // for(int i=1;i<=20;i++)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         cout<<(c[i][j]%2==lucas(i,j))<<endl;
    //     }
    // }
    // cout<<l
    // cout<<c[2][1]<<endl;
    char ch;
    scanf("%c",&ch);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&ch);
        a[i]=ch-'1';
        if(a[i]==0)c0++;
        else if(a[i]==1)c1++;
        else c2++;
    }
    // cout<<c0<<' '<<c1<<' '<<c2<<endl;
    int cnt=0;
    for(int i=0;i<n;i++)if(a[i]==1)cnt^=lucas(n-1,i);
    if(cnt){
        cout<<1<<endl;
    }else{
        if(c1){
            cout<<0<<endl;
        }else{
            cnt=0;
            for(int i=0;i<n;i++)if(a[i]==2)cnt^=lucas(n-1,i);
            if(cnt){
                cout<<2<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
}