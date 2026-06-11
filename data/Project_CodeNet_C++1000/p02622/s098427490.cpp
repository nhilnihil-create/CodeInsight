#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod  = 1e9 + 7;
const ll INF = 1e14;

void solve(){

    string s1, s2;
    cin >> s1 >> s2;
    int count = 0;
    for(int i = 0; i < s1.length(); ++i){
        if(s1[i] == s2[i]) ++count;
    }

    cout << ((int)s1.length()-count);

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //int test; cin >> test;
    //for(int t = 1; t <= test; ++t){
        solve();    
    //}

	return 0;
}

