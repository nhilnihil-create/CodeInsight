#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,d,a;
    cin >> n >> d >> a;
    vector<pair<int,int>> m(n);
    for(int i = 0; i < n; i++){
        int x,h;
        cin >> x >> h;
        m[i] = {x,h};
    }    
    sort(m.begin(),m.end());
    ll total = 0;
    ll ans = 0;
    d = 2*d;
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        int h = m[i].second;
        int x = m[i].first;
        while(q.size() && q.front().first < x){
            total -= q.front().second;
            q.pop();
        }
        h -= total;
        if(h > 0){
            int num = (h+a-1)/a;
            ans += num;
            total += num*a;
            q.push({x+d,num*a});
        }
    }
    cout << ans << endl;
    return 0;
}