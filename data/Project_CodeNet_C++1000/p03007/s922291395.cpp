#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n, ans;
vector<Int> an, ap;
using P = pair<Int, Int>;
vector<P> v;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(Int i=0; i<n; ++i){
		Int a;
		cin >> a;
		if(a < 0) an.push_back(a);
		else ap.push_back(a);
	}
	sort(an.begin(), an.end());
	sort(ap.begin(), ap.end());
	if(ap.empty()){
		for(size_t i=0; i<an.size()-1; ++i){
			v.push_back(P(an.back(), an[i]));
			an.back() -= an[i];
		}
		ans = an.back();
	}else if(an.empty()){
		for(size_t i=1; i<ap.size()-1; ++i){
			v.push_back(P(ap[0], ap[i]));
			ap[0] -= ap[i];
		}
		v.push_back(P(ap.back(), ap[0]));
		ans = ap.back() - ap[0];
	}else if(ap.size() <= an.size()){
		vector<Int> a(4*ap.size());
		size_t cp = 0, cn = 0;
		for(size_t i=0; i<2*ap.size(); ++i){
			size_t j=2*ap.size()-1+i;
			size_t k=j;
			Int f = 1;
			while(j > 0){
				if(j % 2 == 0) f *= -1;
				j = (j-1) / 2;
			}
			if(f == 1){
				a[k] = ap[cp];
				++cp;
			}else{
				a[k] = an[cn];
				++cn;
			}
		}
		for(Int i=2*ap.size()-2; i>=0; --i){
			v.push_back(P(a[2*i+1], a[2*i+2]));
			a[i] = a[2*i+1] - a[2*i+2];
		}
		for(size_t i=ap.size(); i<an.size(); ++i){
			v.push_back(P(a[0], an[i]));
			a[0] -= an[i];
		}
		ans = a[0];
	}else{
		vector<Int> a(4*an.size());
		size_t cp = 0, cn = 0;
		for(size_t i=0; i<2*an.size(); ++i){
			size_t j=2*an.size()-1+i;
			size_t k=j;
			Int f = 1;
			while(j > 0){
				if(j % 2 == 0) f *= -1;
				j = (j-1) / 2;
			}
			if(f == 1){
				a[k] = an[cn];
				++cn;
			}else{
				a[k] = ap[cp];
				++cp;
			}
		}
//		for(size_t i=0; i<a.size(); ++i)
//			cout << i << " " << a[i] << "\n";
		for(Int i=2*an.size()-2; i>=0; --i){
			v.push_back(P(a[2*i+1], a[2*i+2]));
			a[i] = a[2*i+1] - a[2*i+2];
		}
//		cout << a[0] << "\n";
		for(size_t i=an.size(); i<ap.size()-1; ++i){
			v.push_back(P(a[0], ap[i]));
			a[0] -= ap[i];
		}
		v.push_back(P(ap.back(), a[0]));
		a[0] = ap.back() - a[0];
		ans = a[0];
	}
	cout << ans << "\n";
	for(auto i:v) cout << i.first << " " << i.second << "\n";
}