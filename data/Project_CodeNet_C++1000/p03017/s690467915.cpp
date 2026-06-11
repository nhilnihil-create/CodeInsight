#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
	string s;cin>>s;
	for(int i = a - 1; i < max(d,c) - 1; i++) {
		if(s[i - 1] == '#' && s[i] == '#'){
			cout << "No" << endl;
			return 0;
		}
	}
	if (c > d){
		bool flag = false;
	for(int i = b - 1; i < d; i++) {
		if(s[i] == '.' && s[i] == s[i + 1] && s[i] == s[i - 1]){
			flag = true;
		}
	}
	if(!flag){
		cout << "No" << endl;
		return 0;
	}
	}
	cout << "Yes" << endl;
	return 0;
}