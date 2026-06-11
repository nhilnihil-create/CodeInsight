#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ll a,b;
  cin >> a >> b;
  string str;
  cin >> str;
  vector <ll> arr(a);
  for (int z=0;z<a;z++){
    arr[z] = str[z]-'0';
  }
  ll temp=0;
  if((b==2)||(b==5)){
    for (int z=0;z<a;z++){
      if((arr[z]%b==0)||(arr[z]==0)){
        temp+=z+1;
      }
    }
    cout << temp << endl;
  }
  else{
    vector <ll> power(a+1);
    power[0] = 1;
    for (int z=1;z<=a;z++){
        power[z] = power[z-1]*10;
        power[z] %= b;
    }

    vector <ll> suf(a);
    suf[a-1] = arr[a-1]%b; 
    map<ll,ll> mapp;
    mapp[arr[a-1]%b]++;
    ll ans = 0;
    ll i = 1;

    for (int z=a-2;z>=0;z--){
      suf[z] = (suf[z+1]+arr[z]*power[i])%b;
      ans += mapp[suf[z]];
      mapp[suf[z]]++;
      i++;
    }
    cout << ans+mapp[0] << endl; 
  }

   
}
  