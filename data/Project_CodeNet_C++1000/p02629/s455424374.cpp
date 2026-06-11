#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;

int main(){
  ll n; cin>>n;
  string ans = "";
  char add = 'a';
  while(n){
      n--;
      char now = add + (n%26);
      ans = now+ans;
      n /= 26;
  }
  cout<<ans<<endl;
}
