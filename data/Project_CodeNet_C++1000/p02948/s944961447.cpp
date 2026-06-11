#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> work;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a,b);
        work.push_back(p);
    }
    sort(work.begin(), work.end());
    priority_queue<ll> money;
    int count=0;
    ll ans=0;
    for(int i=1; i<=m; i++){
        //m-i日目の仕事を決める。
        if(count < n){
            while(work.at(count).first==i){
            money.push((ll)work.at(count).second);
            count++;
            if(count == n) break;
            }
        }
        if(money.empty()) continue;
        ans += money.top();
        money.pop();
    }
    cout << ans << endl;
}
