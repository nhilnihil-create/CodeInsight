#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  char key = s[0];
  int ans = 1;
  int count = 1;
  bool flag = false;
  rep1(i,s.size()-1){
    if(count == 0){
      ans++;
      count = 1;
      key = s[i];
    }
    else if(count == 2){
      ans++;
      count = 0;
    }
    else if(key != s[i]){
      ans++;
      key = s[i];
    }
    else if(key == s[i]){
      count++;
    }
    //cout << count << " " << ans << endl;
  }
  if(count == 1 && s[s.size() -2] == s[s.size()-1]) ans--;
  cout << ans + 1 << endl;
}

