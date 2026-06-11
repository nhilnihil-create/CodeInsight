#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p=0;
    if(n<10)
        cout<<n<<endl;
    else{
        int a[10][10];
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){
                a[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            int l=s.size();
            if(s[l-1]!='0'){
                int x=s[0]-'0';
                int y=s[l-1]-'0';
                //swap(s[0],s[l-1]);
                a[x][y]++;
            }
        }
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){
                p+=a[i][j]*a[j][i];
            }
        }
        cout<<p<<endl;

    }
}