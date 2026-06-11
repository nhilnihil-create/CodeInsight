#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

pair<int,int> beto(int x) {
    string s = to_string(x);
    
    return pair<int,int> (s.front(), s.back());
}

int main() {
    int n;
    cin >> n;

    map<pair<int,int>, int> m;
    for(int i = 1; i <= n; i++) {
        pair<int,int> p = beto(i);
        m[p]++;
    }
    
    long int cnt = 0;
    for(int i = 1; i <= n; i++) {
        pair<int,int> pa = beto(i);
        pair<int,int> pb(pa.second, pa.first);
        
        //cout << pa.first << endl;
        //cout << m[pa] << " " << m[pb] << endl;
        cnt += m[pb];
    }
    
    cout << cnt << endl;
    
    
    return 0;
}
