#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	int N;
  	string S,T;
	cin >> N >> S >> T;

  	string ans;
	rep(i, N){
      ans.push_back(S.at(i));
      ans.push_back(T.at(i));
    }
  	cout << ans << endl;
}
