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
 string s;cin>>s;
 int l=s.length();int k=0;
 for(i=0;i<l/2;i++)
 {
     if(s[i]!=s[l-i-1]) k++;
 }
  cout<<k<<endl;
}
