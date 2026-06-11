#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
  vector<string> S{"SUN","MON","TUE","WED","THU","FRI","SAT"};
  string s;cin>>s;
  rep(i,S.size()){
    if(s==S[i]) cout<<7-i<<endl;
  }
}