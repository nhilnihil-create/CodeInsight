#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, pair<ll, ll> > p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    vector<ll> F(N);

    ll count = 0;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        count += A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> F[i];
    }

    if(count <= K) {
        cout << 0 << endl;
        return 0;
    }

    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());

    vector<ll> X(N);

    for(int i = 0; i < N; i++) {
        X[i] = A[i] * F[i];
    }

    ll mx = *max_element(X.begin(), X.end());

    ll line = mx;

    count = 0;

    ll front = 0LL;
    ll back = mx;
    
    ll mid = (front + back) / 2LL;

    while(front < back) {
        ll c_c = 0;
        for(int i = 0; i < N; i++) {
            if(mid < X[i]) {
                ll c = (X[i] - mid) / F[i];
                if(c * F[i] != X[i] - mid) {
                    c++;
                }
                c_c += c;
            }
        }
        if(c_c <= K) {
            count = c_c;
            line = mid;
            back = mid;
        } else {
            front = mid + 1LL;
        }
        mid = (front + back) / 2LL;
    }

    for(int i = 0; i < N; i++) {
        if(line < X[i]) {
            ll c = (X[i] - line) / F[i];
            if(c * F[i] != X[i] - line) {
                c++;
            }
            A[i] -= c;
            X[i] = A[i] * F[i];
        }
    }

    K -= count;

    priority_queue<p> pq;

    for(int i = 0; i < N; i++) {
        pq.push(make_pair(X[i], make_pair(A[i], F[i])));
    }

    while(K) {
        K--;
        ll x = pq.top().first;
        ll a = pq.top().second.first;
        ll f = pq.top().second.second;
        pq.pop();
        a--;
        pq.push(make_pair(a * f, make_pair(a, f)));
    }

    cout << pq.top().first << endl;
}