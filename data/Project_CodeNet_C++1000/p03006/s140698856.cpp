#include<bits/stdc++.h>
#define llint long long
 
using namespace std;
typedef pair<llint, llint> P;
 
int n;
llint x[55], y[55];
set<P> S;
 
int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	
	llint ans = n+1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(x[i] == x[j] && y[i] == y[j]) continue;
			if(x[i] > x[j]) continue;
			llint p = x[j]-x[i], q = y[j]-y[i];
			
			S.clear();
			for(int i = 1; i <= n; i++) S.insert(make_pair(x[i], y[i]));
			llint tmp = 0;
			P pre; bool first = true;
			while(S.size()){
				P nx = make_pair(pre.first + p, pre.second + q);
				if(!first && S.count(nx)){
					pre = nx;
					S.erase(nx);
				}
				else{
					pre = *S.begin();
					S.erase(S.begin());
					tmp++;
				}
				first = false;
			}
			//cout << p << " " << q << " " << tmp << endl;
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
	
	return 0;
}