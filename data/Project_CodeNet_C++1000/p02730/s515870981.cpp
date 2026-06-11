#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

bool ok(string s){
	int n= s.length();
	bool maki = true;
	for(int i=0;i<n/2;i++){
		if(s[i] != s[n-i-1]) maki = false;
	}
	return maki;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();

    if(ok(s) && ok(s.substr(0, n / 2)) && ok(s.substr(n / 2 + 1, n / 2))){
    	cout << "Yes" << endl;
    }else{
    	cout << "No" << endl;
    }
    return 0;
}
