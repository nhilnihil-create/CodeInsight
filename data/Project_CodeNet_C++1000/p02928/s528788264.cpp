#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,k;
  cin >> n >> k;
  vector<long long>a(n);
  for(int i=0;i<n;i++)
  cin >> a.at(i);
  const long long mod=1000000007;
  vector<pair<int,int>>tnt(n,pair<long long,long long>(0,0));
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          if(a.at(i)>a.at(j)){
            if(i<j) tnt.at(i).first++;
            else tnt.at(i).second++;
          }
      }
  }
  //for(int i=0;i<n;i++)
    //cout << tnt.at(i).first << '$' << tnt.at(i).second << endl;
  long long ans=0;
  for(int i=0;i<n;i++){
    ans=((ans+k*(k+1)/2%mod*tnt.at(i).first%mod)+k*(k-1)/2%mod*tnt.at(i).second%mod)%mod;
  }
  cout << ans << endl;
  return 0;
}