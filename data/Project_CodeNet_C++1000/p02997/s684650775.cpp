#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;cin>>n>>k;
	int cpy = n - 2;
	cpy*=(cpy + 1);
	cpy/=2;
	if(k > cpy){
		cout<<-1<<endl;
	} else{
		vector<int> edges[n+1];
		int cnt = cpy;
		int y = 0;
		for(int i = 2;i <= n; ++i){
			edges[1].push_back(i);
			y++;
		}
		cnt -= k;
		for(int i = 2; i <= n&& cnt; ++i){
			for(int j = i + 1; j <=n && cnt; ++j){
				cnt--;
				edges[i].push_back(j);
				y++;
			}
		}
		cout<<y<<endl;
		for(int i = 1; i <= n; ++i){
			for(auto x : edges[i]){
				cout<<i<<" "<<x<<endl;
			}
		}

	}
	return 0;
}

