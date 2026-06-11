#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

char addChar(int i, char s){
  int tmp = int(s) + i;
  if(tmp > 90) tmp -= 26;
  return char(tmp);
}

int main() {
	string S;
  	int N;
	cin >> N >> S;
 
  	string ans;
  	int ans2;
  	rep(i, S.size()) ans.push_back(addChar(N, S.at(i)));
  	
  	cout << ans << endl;
}
