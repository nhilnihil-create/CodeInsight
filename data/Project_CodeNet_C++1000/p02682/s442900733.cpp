#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,k,k1;
  cin >> a >> b >> c >> k;
  long long ans;
  k1=k;
  k-=a;
  if(k<=0){
    ans=k1;
    cout << ans << endl;
    return 0;
  }
  k1-=a;
  k-=b;
  if(k<=0){
    ans=a+k1*0;
    cout << ans << endl;
    return 0;
  }
  k1-=b;
  k-=c;
  if(k<=0){
    ans=a+b*0-k1;
    cout << ans << endl;
    return 0;
  }
}