/*Anup Ghosh*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi acos(-1)
#define ull unsigned long long
#define nl printf("\n")
#define MAXN 1000005
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define fio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
	fio();
	int n;
 string s;
 char y;
 string ans;
 cin>>n>>s;
 int x,i;
 int len=s.size();
 for(i=0;i<len;i++){
 x=s[i]-'A';
 x=(x+n)%26;
 y='A'+x;
 ans=ans+y;
 }
 cout<<ans<<endl;
	return 0;
}
