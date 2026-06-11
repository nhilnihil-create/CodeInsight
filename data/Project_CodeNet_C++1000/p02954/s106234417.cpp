#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n, i##_len=(n); i>=0; i--)
#define FOR(i,a,b) for(int i=(a), i##_len=(b); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
} 

int main(){
string S;
cin >> S;

int N = S.size();
int tmp = 0;
vector<int>ans(N, 0);
REP(j, 2){
REP(i, N){
	if(S.at(i) == 'R') tmp++;
	else {
		ans.at(i) += tmp / 2;
		ans.at(i - 1) += (tmp + 1) / 2;
		tmp = 0;
	}
}

reverse(all(ans));
reverse(all(S));

REP(k, N){
	if(S.at(k) == 'R') S.at(k) = 'L';
	else S.at(k) = 'R';
}
}

REP(i, N){
	cout << ans.at(i) << endl;
}
}
