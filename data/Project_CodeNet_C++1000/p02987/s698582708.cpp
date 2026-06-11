#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
    cin >> s;
    map<int,int> cnt;
    rep(i,4){
      cnt[s[i]]++;
    }
  if(cnt.size() == 2) cout << "Yes" << endl;
  else cout << "No" << endl;
}

// cout << fixed << setprecision(15) <<  << endl;
