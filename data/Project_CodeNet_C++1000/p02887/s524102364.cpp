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
 int n;cin>>n;string s;cin>>s;
 int c=0;
 for(i=0;i<s.length();i++)
 {
     if(s[i]==s[i+1]) continue;
     else c++;
 }
 cout<<c<<endl;
}
