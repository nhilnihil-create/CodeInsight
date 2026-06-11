#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;

  if(n%2==1)cout << 0 << endl;
  else{
    ll s=0;//5の個数
    ll d=10;
    while(n>=d){
      //s+=floor(n/d);
      s+=n/d;
      d*=5;
      //cout << floor(n/(2*pow(5,c))) <<" " <<c<< endl;
    }

    cout << s << endl;
  }

}