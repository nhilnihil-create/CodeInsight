#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int n;
pair<int,int> pt[maxn];

int sim(pair<int,int> p) {
    int res = 0;
    set<pair<int,int>> act;
    for (int i=0; i<n; i++) {
	act.insert(pt[i]);
    }

    while (act.size()) {
	res++;
	auto cur = *act.begin();
	act.erase(act.begin());
	while (1) {
	    cur.first += p.first;
	    cur.second += p.second;
	    if (act.count(cur)) {
		act.erase(cur);
	    } else {
		break;
	    }
	}
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>pt[i].first>>pt[i].second;
    }

    set<pair<int,int>> st;
    
    for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {
	    if (i==j) continue;
	    int dx=pt[j].first-pt[i].first;
	    int dy=pt[j].second-pt[i].second;
	    st.insert({dx,dy});
	}
    }

    int ans = n;
    for (auto p: st) {
	ans = min(ans, sim(p));
    }
    cout<<ans<<endl;
    
    
    return 0;
}
