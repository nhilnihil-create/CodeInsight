#include<bits/stdc++.h>
#define int long long
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
#define mod 1000000009
#define garou99 ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main() {
  string s,t;
  cin>>s>>t;
  int m=s.length();
  int n=t.length();
  if(n>m){
	  cout<<0;
	  return 0;
  }
  int mn=INT_MAX,j=0;
  for(int i=0;i<=m-n;i++){
	  int x=i,z=0;
	for(int j=0;j<n;j++){
   if(s[i+j]!=t[j])
   z++;
   x++;
	} 
	mn=min(mn,z);
  }
//   if(mn==INT_MAX)
//   mn=n;
  cout<<mn;
	}