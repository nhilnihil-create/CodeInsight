#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;

int n;

vector<pair<double,double>> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    v.resize(n);
    for (int i=0; i<n; i++) {
	cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end(),[&](pair<double,double> p, pair<double,double> q) {
	    return atan2(p.second,p.first) < atan2(q.second,q.first);
	});


    double res = 0;
    for (int i=0; i<n; i++) {
	double dx = 0;
	double dy = 0;
	for (int j=i; j<2*n && j-i<n; j++) {
	    dx += v[j%n].first;
	    dy += v[j%n].second;
	    double cur = sqrt(dx*dx + dy*dy);
	    res = max(res, cur);
	}
    }

    cout<<fixed<<setprecision(12)<<res<<endl;    
    return 0;
}
