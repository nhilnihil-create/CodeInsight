#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  


int n;
vector<string> ans;
void dfs(string s, char maxi='a'){
  
  if(n==s.length()){
    ans.push_back(s);
    return;
  }
  for(char i='a'; i<=maxi; i++){
    string ns = s+i;
    if(i==maxi) dfs(ns, maxi+1);
    else dfs(ns, maxi);
  }

}


int main(){
  cin >> n;
  ll res=0;
  dfs("", 'a');
  sort(ans.begin(), ans.end());
  for(auto x: ans) cout << x << endl;
}