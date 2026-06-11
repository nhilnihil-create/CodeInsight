#include<stack>
#include<queue>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
long long comp(long long n,long long k){
  long long ans=1,i;
  for(i=1;i<=k;i++){
    ans=ans*(n-i+1)/i;
  }
  return ans;
}
int main(){
  map<long long,long long> x;
  long long ans=0,tmp=1,i,a[200010],n,p;
  string s;
  scanf("%lld %lld\n",&n,&p);
  cin >> s;
  if(p==2 || p==5){
    for(i=0;i<s.size();i++){
      if((s[i]-'0')%p==0){
        ans+=i+1;
      }
    }
    printf("%lld\n",ans);
    return 0;
  }
  reverse(s.begin(),s.end());
  a[0]=0;
  for(i=0;i<s.size();i++){
    a[i+1]=(a[i]+(s[i]-'0')*tmp)%p;
    tmp=tmp*10%p;
  }
  vector<long long> b;
  for(i=0;i<=s.size();i++){
    if(x[a[i]]==0){
      b.push_back(a[i]);
    }
    x[a[i]]++;
  }
  for(i=0;i<b.size();i++){
    ans=ans+comp(x[b[i]],2);
  }
  printf("%lld\n",ans);
  return 0;
}