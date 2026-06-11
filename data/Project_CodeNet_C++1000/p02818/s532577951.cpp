#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
  ll a,b,k;
  cin >> a >> b >> k;
  if(a < k){
    b -= k - a;
    a = 0;
    if(b < 0) b = 0;
  }else{
    a -= k;
  }
  cout << a << " " << b << endl;
}