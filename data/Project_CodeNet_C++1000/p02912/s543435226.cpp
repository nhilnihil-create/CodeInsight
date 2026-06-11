#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<ll> q;
    ll all=0;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        q.push(a);
        all += a;
    }
    ll discount = 0;
    for(int i=0; i<m; i++){
        ll use;
        use = q.top();
        q.pop();
        discount += (use+1)/2;
        q.push(use/2);
    }
    cout <<  all - discount << endl;
}
