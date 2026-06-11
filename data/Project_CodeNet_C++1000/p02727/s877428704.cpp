#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, char>
using namespace std;

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    priority_queue<P> que;

    for(int i=0;i<a;i++){
        ll p;
        cin >> p;
        que.push(P(p, 'a'));
    }
    for(int i=0;i<b;i++){
        ll q;
        cin >> q;
        que.push(P(q, 'b'));
    }
    for(int i=0;i<c;i++){
        ll r;
        cin >> r;
        que.push(P(r, 'c'));
    }

    ll ans = 0, sum_a = 0, sum_b = 0, sum = 0;
    while(!que.empty()){
        P p = que.top();
        que.pop();
        if(p.second == 'a' && sum_a < x && sum < x+y){
            ans += p.first;
            sum_a++;
            sum++;
        }else if(p.second == 'b' && sum_b < y && sum < x+y){
            ans += p.first;
            sum_b++;
            sum++;
        }else if(p.second == 'c' && sum < x+y){
            ans += p.first;
            sum++;
        }
    }

    cout << ans << endl;
}