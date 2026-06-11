#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	int cnt = 0;
	int tmp = 0;
	for(int i = 0; i < n + 1; i++) {
		if(s[i] == '0'){
			tmp = max(tmp,cnt);
			cnt = 0;
		}
		else{
			cnt ++;
		}
	}
	tmp = max(tmp,cnt);
	if(tmp >= m){
		cout << -1 << endl;
		return 0;
	}
	reverse(ALL(s));
	int i = 0;
	vector<int> ans;
	while(i < n){
		int right = min(n,i + m);
		for(int j = right; j > i; j--) {
			if(s[j] == '1'){
				continue;
			}
			else{
				ans.pb(j - i);
				i = j;
				break;
			}
		}
	}

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[ans.size() - i - 1] << " ";
	}

	return 0;
}