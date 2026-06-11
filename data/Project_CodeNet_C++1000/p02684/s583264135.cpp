#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<int> nx(n);
    for(int i = 0; i < n; i++){
        cin >> nx[i];
        nx[i]--;
    }
    vector<int> ord(n, -1), s;
    int u = 0;
    while(ord[u] == -1){
        ord[u] = s.size();
        s.push_back(u);
        u = nx[u];
    }
    int loop = s.size() - ord[u];
    if(k <= ord[u]){
        cout << s[k]+1 << endl;
    } else {
        cout << s[(k-ord[u]) % loop + ord[u]]+1 << endl;
    }
    return 0;
}