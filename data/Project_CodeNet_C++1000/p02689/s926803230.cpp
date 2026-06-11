#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod  = 1e9 + 7;
const ll INF = 1e14;


void solve(){

    int n, m; cin >> n >> m;
    vector<int> ht (n);
    vector<bool> valid (n, true);
    for(int& it : ht) cin >> it;
    while(m--){
        int a, b; cin >> a >> b;
        --a, --b;
        if(ht[a] >= ht[b]) valid[b] = false;
        if(ht[a] <= ht[b]) valid[a] = false;
    }
    cout << count(valid.begin(), valid.end(), true);
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

