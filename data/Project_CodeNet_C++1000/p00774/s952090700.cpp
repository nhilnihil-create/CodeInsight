#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define loop(i,a,b) for(int i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)
#define all(a) (a).begin(), (a).end()

const double eps = 1e-10;
const double pi  = acos(-1.0);
const double inf = (int)1e8;

int main(){
	int n;
	while(cin >> n, n){
		vector<vector<int> > v(n);
		for(int i=0; i< n; i++){
			for(int j=0; j < 5; j++){
				int m; cin >> m; v[i].push_back(m);
			}
		}
		int ret = 0;

		while(true){
			bool p = false;
			for(int i=0; i < n; i++){
				for(int j=0; j< 3; j++){
					if(v[i][j] == -1) continue;
					int count = 0;
					while(v[i][j] == v[i][j+count] && j+count < 5) count++;
					if(3 <= count){
						p = true; ret += v[i][j]*count;
						rep(k, count) v[i][j+k] = -1;
					}
				}
			}
			if(!p) break;
			else {
				for(int i=n-1; 1 <= i; i--){
					for(int j=0; j< 5; j++){
						if(v[i][j] == -1){
							for(int k =0; 0 <= i-k; k++) if(v[i-k][j] != -1){
								v[i][j] = v[i-k][j]; v[i-k][j] = -1; break;
							}
						}
					}
				}
			}
		}
		cout << ret << endl;
	}
}