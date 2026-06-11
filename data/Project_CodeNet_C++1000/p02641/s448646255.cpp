#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod  = 1e9 + 7;
const ll INF = 1e14;

void solve(){

    int x, n; cin >> x >> n;
    unordered_set<int> set;
    while(n--){
        int num; cin >> num;
        set.insert(num);
    }
    int pos = 0;
    while(true){
        if(set.find(x-pos) == set.end()){
            cout << x-pos;
            return;
        }
        if(set.find(x+pos) == set.end()){
            cout << x+pos;
            return;
        }
        ++pos;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

	return 0;
}

