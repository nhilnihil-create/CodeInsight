
#include <bits/stdc++.h>
#define reps(i,j,k) for(int i=j;i<k;++i)
#define rep(i,j) reps(i,0,j)
#define fr first
#define sc second
#define fs fr
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int f(int a, int l){
	vi v(l);
	int idx = 0;
	while(a>0){
		v[idx++] = a%10;
		a/=10;
	}
	sort(v.begin(), v.end());
	int bg = 0, sm = 0;
	rep(i,l){
		bg = bg * 10 + v[l-1-i];
		sm = sm * 10 + v[i];
	}
	return bg - sm;
}

int main(){
	int a, l;
	while(cin >> a >> l, l){
		map<int, int> memo;
		memo[a] = 1;
		int ans = 1;
		for(;;){
			a = f(a, l);
			if(memo[a]){
				cout << memo[a]-1 << " " <<  a << " " << ans - memo[a] + 1 << endl;
				break;
			}
			memo[a] = ++ans;
		}
	}
	return 0;
}