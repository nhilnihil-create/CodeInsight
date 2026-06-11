#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

vector<ll> A, F;    //Fは降順
vector<pair<ll, P> > S;
ll N, K;

bool check(ll x) {
    ll M = 0;

    for (int i = 0; i < N; i++) {
        if (S[i].first > x) {
            ll a = S[i].second.first, f = S[i].second.second, s = S[i].first;
            M += (s-x+f-1)/f;
        }
    }

    return M <= K;
}

int main() {
    cin >> N >> K;
    A.resize(N), F.resize(N), S.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> F[i];
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    for (int i = 0; i < N; i++)
        S[i] = pair<ll,P> (A[i] * F[N-1-i], P(A[i], F[N-1-i]));
    
    sort(S.begin(), S.end(), greater<pair<ll,P> >());

    ll l = -1, r = 1e12, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;

        if (check(mid))
            r = mid;
        else 
            l = mid;
    }

    cout << r << endl;
    return 0;
}