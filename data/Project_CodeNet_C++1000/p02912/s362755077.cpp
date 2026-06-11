#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    for(int i = 0, a; i < n; i++){
        cin >> a;
        pq.push(a);
    }
    while(m--){
        int temp = pq.top();
        pq.pop();
        pq.push(temp/2);
    }
    ll ans = 0;
    while(pq.size()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}
