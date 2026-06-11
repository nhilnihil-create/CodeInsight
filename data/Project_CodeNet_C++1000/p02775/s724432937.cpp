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

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
const int inf = 1001001000;
const long long int Inf = 1001001001001001000;

void print(vector<vector<int>> a){
	for (int i=0;i<a.size();i++){
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

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}



int main()
{
	string s;
	cin >> s;
	reverse(all(s));
	s = s + '0';
	int n = s.size();
	vector<vector<int>> dp(n+1,vector<int>(2,inf));
	dp[0][0] = 0;
	rep(i,n){
		rep(j,2){
			int x = s[i] - '0';
			x += j;
			rep(a,10){
				int ni = i + 1, nj = 0;
				int b = a - x;
				if (b < 0){
					nj = 1;
					b += 10;
				}
				dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
			}
		}
		
	}
	cout << dp[n][0] << endl;

	return 0;
}