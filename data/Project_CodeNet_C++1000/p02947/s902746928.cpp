#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string>s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  for(int i=0;i<n;i++) sort(s[i].begin(), s[i].end());
  sort(s.begin(), s.end());

  ll ans = 0;
  int sum = 1;
  for(int i=1;i<n;i++){
    if(s[i] == s[i-1]){
      ans += sum;
      sum++;
    }else{
      sum = 1;
    }
  }

  cout << ans << endl;
}