#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num,l,r,k;
    vector< vector<int> >c(10,vector<int>(10));
    for(int i=1;i<=n;i++)
    {
       r=i%10;
       num=i;
       while(num!=0)
       {
           k=num%10;
           num=num/10;
       }
       l=k;
       c[l][r]++;
    }
    long long int total=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            total+=c[i][j]*c[j][i];
        }
    }
    cout<<total<<endl;
    return 0;

}
