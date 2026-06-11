#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main(){
    int n; cin>>n;
    set<int> s;
    rep(i, n){
        int x; cin >> x;
        s.insert(x);
    }
    if(n == s.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
