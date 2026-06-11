#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n; 
    cin >> n; 
    vector<int> p(n), o(n);
    rep(i,n) cin >> p[i];
    o = p;
    sort(p.begin(),p.end());
    int count = 0;
    rep(i,n) if(p[i] != o[i]) count++;
    if(count<=2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}