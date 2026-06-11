#include<bits/stdc++.h>
using namespace std;
#define M 2019
int cnt[M];
int main(){
  string s;
  cin>>s;
  int n=s.length();
  int pot=1;
  int suf=0;
  cnt[suf]++;
  long long int ans=0;
  for(int i=n-1;i>=0;i--){
    int dig=s[i]-'0';
    suf=(suf+pot*dig)%M;
	ans+=cnt[suf];
    cnt[suf]++;
    pot=(pot*10)%M;
  }
  cout<<ans<<"\n";
  return 0;
}
