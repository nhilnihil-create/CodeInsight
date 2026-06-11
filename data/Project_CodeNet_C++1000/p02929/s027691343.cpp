#include<iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main(){
  ll n,ans=1,tmp;
  string lr;
  string s;
  cin >> n>> s;
  ll lsum[n*2],rsum[2*n];
  fill(lsum,lsum+2*n,0);
  fill(rsum,rsum+2*n,0);
  if(s[0]=='W'||s[2*n-1]=='W'){
    cout << "0\n";
    return 0;
  }
  lsum[0]=1;
  for(int i=1;i<=n*2;i++){
    lsum[i]=lsum[i-1];
    rsum[i]=rsum[i-1];
    if(i%2==0){
      if(s[i]=='W'){
        rsum[i]++;
        lr+="r";
      }else{
        lsum[i]++;
        lr+="l";
      }
    }else{
      if(s[i]=='W'){
        lsum[i]++;
        lr+="l";
      }else{
        rsum[i]++;
        lr+="r";
      }
    }
  }
  if(rsum[n*2-1]!=lsum[n*2-1]){
    cout <<"0\n";
    return 0;
  }
  for(int i=0;i<n*2;i++){
    if(lr[i]=='r'){
      ans *= (lsum[i]-rsum[i]);
      ans %= MOD;
    }
  }
  for(int i=1;i<=n;i++){
    ans *= i;
    ans %= MOD;
  }

  cout << ans<<endl;
}
