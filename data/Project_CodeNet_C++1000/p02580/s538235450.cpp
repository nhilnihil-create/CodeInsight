#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef pair<int,int> pii;
const int mod = (int) 1000000007;
const int inf = (int) 2e18;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout << fixed << setprecision(9);
	#ifdef LOCAL_DEFINE
		freopen("in.txt", "rt", stdin);
	#endif
  	int h, w, m, x, y;
    map<int, int> mx;
    map<int, int> my;
  	set<pii> s;
  	cin >> h >> w >> m;
  	while(m--){
  	    cin >> x >> y;
  	    mx[x]++;
  	    my[y]++;
  	    s.insert({x, y});
  	}
  	int xf, xs = 0;
  	vector<int> vx, vy;
  	for(auto it : mx){
  	    if(it.second > xs){
  	        xs = it.second;
  	        xf = it.first;
  	    }
  	}
  	for(auto it : mx){
  	    if(it.second == xs){
  	        vx.push_back(it.first);
  	    }
  	}
  	int yf, ys = 0;
  	for(auto it : my){
  	    if(it.second > ys){
  	        ys = it.second;
  	        yf = it.first;
  	    }
  	}
  	for(auto it : my){
  	    if(it.second == ys){
  	        vy.push_back(it.first);
  	    }
  	}
  	int res = xs + ys - 1;
  	bool ok = true;
  	for(int i=0; i<vx.size(); i++){
  	    if(!ok) break;
  	    for(int j=0; j<vy.size(); j++){
  	        if(s.find({vx[i], vy[j]}) == s.end()){
  	            res += 1;
  	            ok = false;
  	            break;
  	        }
  	    }
  	}
  	cout << res << "\n";
}