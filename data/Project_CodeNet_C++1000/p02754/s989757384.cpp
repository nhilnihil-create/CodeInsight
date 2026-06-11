#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  ll t = n/(a+b);
  if(n - (a+b)*t >= a){
    cout << a*t + a << endl;
  }else{
    cout << a*t +  n - (a+b)*t << endl;
  }
}