#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> ab;
    rep(i, n){
        int a, b;
        cin >> a >>b;
        ab.push_back(P(a,b));
    }
    sort(ab.begin(), ab.end());
    priority_queue<int> can;
    int j = 0;
    int ans = 0;
    for(int i = 1; i<m+1; i++){
        while(j<n){
            if(ab[j].first<=i){
                can.push(ab[j].second);
                j++;
                continue;
            }else break;
        }
        if(!can.empty()){
            ans += can.top();
            can.pop();
        }
    }
    cout << ans << endl;
    return 0;
}