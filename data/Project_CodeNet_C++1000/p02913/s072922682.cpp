#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}


int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  for (int i = n - 1; i >= 0; --i)
  {
	  for (int j = n - 1; j >= 0; --j)
	  {
		  if (s[i] != s[j])
			  dp[i][j] = 0;
		  else
			  dp[i][j] = dp[i + 1][j + 1] + 1;
	  }
  }
  int ans = 0;
  rep(i,n)rep(j,n) {
    if (i >= j) continue; // i < j;
    int now = min(dp[i][j], j-i);
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}