#include<bits/stdc++.h>
#include<boost/variant.hpp>
using namespace std;
typedef long long ll;
typedef vector<boost::variant<bool, ll, int, string, double, char*, const char*>> any;
template<typename T> inline void pr(const vector<T> &xs){
	for(int i=0; i<xs.size()-1; i++) cout<<xs[i]<<" ";
	(xs.empty()?cout:(cout<<xs[xs.size()-1]))<<endl;
}
#ifdef DEBUG
#define debug(...) pr(any{__VA_ARGS__})
#define debugv(x) pr((x))
#else
#define debug(...)
#define debugv(x)
#endif

int main(){
	string S;
	cin >> S;

	int N = S.size();
	int ans=1;
	int i=1;
	int j=1;
	while(i<N){
		int k=1;
		if(S.substr(i-j, j) == S.substr(i, k)) k++;
		j = k;
		i += k;
		if(i<=N) ans++;
	}
	cout << ans << endl;

	return 0;
}
