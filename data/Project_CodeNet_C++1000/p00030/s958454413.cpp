#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cctype>

#define mp make_pair
#define pb push_back
#define REP(i,a,n) for(int i = a;i < (n);i++)
#define rep(i,n) for(int i = 0;i < (n);i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int,int> pii;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

int n,s;

int solve(int cnt,int sum,int now){
	if(cnt == 10){
		return sum == s && now == n;
	}
	int res1 = solve(cnt + 1,sum + cnt,now + 1);
	int res2 = solve(cnt + 1,sum,now);
	return res1 + res2;
}

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	while(1){
		cin >> n >> s;

		if(n == 0 && s == 0) break;

		int ans = solve(0,0,0);

		cout << ans << endl;
	}

	return 0;
}