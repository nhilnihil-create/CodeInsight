#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    int n; cin >> n;
    set<string> s;
    rep(i, n){
        string x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}
