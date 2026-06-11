#include<iostream>
#include<stdio.h>
using namespace std;
using ll=long long;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)
using P=pair<int,int>;
const int mod=1000000007;

int main(){
  int n;
  string s;
cin>>n;
cin>>s;
int ans=0;
for(int i=0;i<=n-3;i++){
  if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')ans++;
}
cout<<ans<<endl;
return 0;
}


