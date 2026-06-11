#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<pair<int,int>> q;
    priority_queue<int> p;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        q.push({-a,b});
    }    
    int now = 1;
    ll ans = 0;
    while(!q.empty() || !p.empty()){
        while(!q.empty() && -q.top().first == now){
            p.push(q.top().second);
            q.pop();
        }
        if(!p.empty()){
            ans += p.top();
            p.pop(); 
        }
        now++;
        if(now == m+1) break;
    }
    cout << ans << endl;
    return 0;
}