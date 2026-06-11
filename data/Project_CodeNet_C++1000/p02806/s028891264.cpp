#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define ote(x) cout<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(s);i<(e);++i)
template<class T> T in(){T x;cin>>x;return x;}
// long long a = in<long long>();

int main(){
	int N; cin>>N;
	vector<string> S(N);
	vector<int> T(N);
	int allT = 0;
	rp(i,0,N){
		string s;int t;
		cin>>s>>t;
		S[i] = s;
		T[i] = t;
		allT += t;
	}
	string X;cin>>X;

	// ote(N);
	// ote(X);
	int ans = 0;
	rp(i,0,N){
		// cout<<S[i]<<" "<<T[i]<<"\n";
		ans += T[i];
		if(S[i] == X){
			ote(allT-ans);
			return 0;
		}
	}

}
