#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

const int M = 1000005;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    
    vector<int> all(M);
    rep(i,n) {
        all[a[i]]++;
    }
    
    bool tf = true;
    for(int i = 2; i < M; i++) {
        int cnt = 0;
        for(int j = i; j < M; j+=i) {
            cnt += all[j];
        }
        if(cnt > 1)
            tf = false;
    }
    
    if(tf) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    
    int g = a[0];
    rep(i,n) {
        g = gcd(g,a[i]);
    }
    
    if(g == 1)
        cout << "setwise coprime" << endl;
    else
        cout << "not coprime" << endl;
    
    
    return 0;
}
