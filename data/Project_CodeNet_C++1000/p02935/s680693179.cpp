#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<double> v(n);
	rep(i,n) cin >> v[i];
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	rep(i,n){
		if(v.size() == 2) break;
		double newone = (v[(int)v.size() - 1] + v[(int)v.size() - 2])/2;
		v.pop_back();
		v.pop_back();
		v.push_back(newone);
	}
    cout << fixed << setprecision(15) << (v[0] + v[1])/2 << endl;
}
