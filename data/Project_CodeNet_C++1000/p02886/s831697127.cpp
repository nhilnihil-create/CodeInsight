//In the name of Allah the Most Merciful
//Astagfirullahil laji Rabbi Minkulli Jamio Watubi elai
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define MX 10000008
#define cs int t;cin>>t;while(t--)
int i,j,k;
int r,s;
main()
{
 int n;cin>>n;int a[n];
 int s=0;for(i=0;i<n;i++)cin>>a[i];
 for(i=0;i<n;i++)
 {
     for(j=i+1;j<n;j++)
     {
        s+=(a[i]*a[j]);
        //cout<<i*j<<endl;
     }
 }
 cout<<s<<endl;

}
