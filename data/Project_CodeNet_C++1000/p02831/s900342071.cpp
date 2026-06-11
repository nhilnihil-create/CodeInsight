#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll gcd(ll a,ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int main(){

  ll a,b;
  cin >> a  >> b;
  cout << a/gcd(a,b)*b << endl;

}