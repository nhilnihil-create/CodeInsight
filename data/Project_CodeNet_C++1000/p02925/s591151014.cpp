#include <iostream>
#include<vector>
#include<queue>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<vector<int>>a(n,vector<int>(n-1));
    vector<queue<int>>b(n);
    rep(i,n) {
        rep(j,n-1) {
            cin >> a[i][j];
            a[i][j]--;
            b[i].push(a[i][j]);
        }
    }
    int ans = 0;
    int all = n*(n-1)/2;
    bool match;
    while(1) {
        vector<int>p(n);
        if(all==0) break;
        match = false;

        rep(i,n) {
            if(b[i].empty()) continue;
            if(p[i]>0 || p[b[i].front()]>0) continue;
            if(b[b[i].front()].front()==i) {
                p[i]++; p[b[i].front()]++;
                b[b[i].front()].pop(); b[i].pop();
                match = true;
                all--;
            }
        }
        if(!match) {
            cout << -1 << endl;
            return 0;
        }
        ans++;
    }
    cout<<ans<<endl;

    return 0;
}
