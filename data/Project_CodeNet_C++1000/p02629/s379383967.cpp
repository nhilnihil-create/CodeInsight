#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  string s="",alf = "abcdefghijklmnopqrstuvwxyz";
  cin>>n;
  while(1){
    n--;
    s=alf[n%26] + s;
    if (!(n / 26)) break;
    n/=26;
  }
  cout <<s<<endl;
}