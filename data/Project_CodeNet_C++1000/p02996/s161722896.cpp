#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> ba(n);
    for(int i = 0; i < n; i++) {
        cin >> ba[i].second >> ba[i].first;
    }
    sort(ba.begin(),ba.end());
    int now=0;
    bool jud=true;
    for(int i = 0; i < n; i++) {
        now+=ba[i].second;
        if(now>ba[i].first) jud=false;
    }
    if(jud) cout << "Yes" << "\n";
    else    cout << "No" << "\n";
    return 0;
}