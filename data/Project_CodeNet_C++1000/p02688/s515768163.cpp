#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod  = 1e9 + 7;
const ll INF = 1e14;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> arr (n, 0);
    while(k--){
        int d; cin >> d;
        while(d--){
            int x; cin >> x;
            ++arr[x-1];
        }
    }
    cout << count(arr.begin(), arr.end(), 0);

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

