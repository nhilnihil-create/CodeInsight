#include <bits/stdc++.h>          
using namespace std;              
typedef long long ll; 

int main() {
    ll N;
    cin >> N;
    queue<ll> a;
    ll a_temp;
    for (ll i=0; i<N; i++) {
        cin >> a_temp;
        a.push(a_temp);
    }
    ll count = 0;
    ll num = 1;
    for (ll i=1; i<=N; i++) {
        if (a.front()==num) {
            a.pop();
            num++;
        }
        else {
            a.pop();
            count++;
        }
    }
    if (count == N) {
        count = -1;
    }
    cout << count << endl;
}