#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using ll = long long int;

const ll T_MAX = 1E+12;

int n;
ll k;
vector<ll> A, F;

int main(){
    cin >> n >> k;
    A.resize(n);
    F.resize(n);
    ll S = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        S += A[i];
    }
    for(int i = 0; i < n; i++)cin >> F[i];
    if (S <= k){
        cout << 0 << endl;
        return 0;
    }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());

    ll lb = 0;
    ll ub = T_MAX;
    while(ub - lb > 1){
        ll mid = (lb + ub) / 2;
        S = 0;
        for(int i = 0; i < n; i++){
            ll need = mid / F[i];
            ll sub = max(0LL, A[i] - need);
            S += sub;
        }
        if (S <= k)ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
    return 0;
}