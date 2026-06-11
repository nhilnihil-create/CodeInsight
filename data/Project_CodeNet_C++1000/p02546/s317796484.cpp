#include "bits/stdc++.h"
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target ("avx,avx2")

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)

void solve(){

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	if(s[(int)s.size()-1] == 's'){
		cout << s << "es" << "\n";
	}else{
		cout << s << "s" << "\n";
	}
}
