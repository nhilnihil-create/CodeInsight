#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
	string s; cin >> s;
	vi iwaiwa,oinuki;
	rep(i,n-1){
		if(s[i]=='#'&&s[i+1]=='#') iwaiwa.push_back(i);
	}
	rep(i,n-2){
		if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.') oinuki.push_back(i);
	}
	rep(i,iwaiwa.size()){
		if(a<=iwaiwa[i]&&iwaiwa[i]<c){
			cout << "No" << endl;
			return 0;
		}
		if(b<=iwaiwa[i]&&iwaiwa[i]<d-2){
			cout << "No" << endl;
			return 0;
		}
	}
	if(c<d){
		cout << "Yes" << endl;
		return 0;
	}else{
		rep(i,oinuki.size()){
			if(b-2<=oinuki[i]&&oinuki[i]<=d-2){
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
	}
}
