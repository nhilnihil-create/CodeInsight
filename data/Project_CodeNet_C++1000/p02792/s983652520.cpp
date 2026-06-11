#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    long long n,i,frst,lst,l,total=0,j;
    map< long long,map<long long,long long> >mp;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        l=i;
        lst=l%10;
        while(l!=0)
        {
            frst=l%10;
            l/=10;
        }
        mp[frst][lst]++;
    }
    for(i=0;i<=9;i++)
    {
        for(j=0;j<=9;j++)
        {
            total+=(mp[i][j]*mp[j][i]);
        }
    }
    cout<<total<<endl;
    return 0;
}