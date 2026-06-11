#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<int> p1(n), p2;
    rep(i,n) cin >> p1[i];
    
    copy(p1.begin(), p1.end(), back_inserter(p2));
    sort(p2.begin(), p2.end());
    
    int cnt = 0;
    rep(i,n) {
        if(p1[i] != p2[i])
            cnt++;
    }
    
    if(cnt == 2 || cnt == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    
    
    
    
    return 0;
}
