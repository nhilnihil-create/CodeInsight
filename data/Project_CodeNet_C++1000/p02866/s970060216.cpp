#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=998244353;
const double EPS=1e-14;
const bool DEBUG=false;

const string YES = "YES";
const string NO = "NO";
const string Yes = "Yes";
const string No = "No";

template<class T>
void debug(T head){
    if(DEBUG){
        cout<<head<<endl;
    }
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cout<<head<<" ";
        debug(body...);
    }
}

/////
ll gcd(ll x, ll y) {
    // C = GCD(X, Y)
    // return C
    ll a = x, b = y;
    ll r;

    r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll pow(ll a, ll n){
    if(n == 0){
        return 1ll;
    }
    if(n == 1){
        return a;
    }
    if(n % 2 == 0){
        ll p = pow(a, n/2);
        return p * p % MOD;
    }else{
        ll p = pow(a, (n-1)/2);
        ll tmp = p * p % MOD;
        return tmp * a % MOD;
    }
}

void answer(ll N, vector<ll>& D){
    if(D[0] != 0){
        cout<<0<<endl;
        return;
    }

    vector<ll> count(N, 0);
    for(auto d : D){
        count[d]++;
    }
    if(count[0] != 1){
        cout<<0<<endl;
        return;
    }


    int max_idx = N-1;
    for(int i=N-1; i>=0; --i){
        if(count[i] == 0){
            max_idx = i-1;
        }else{
            break;
        }
    }
    ull answer = 1;
    for(int i=max_idx; i>0; --i){
        answer *= pow(count[i-1], count[i]);
        answer %= MOD;
    }

    cout<<answer<<endl;

    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    ll N;
    cin>>N;
    vector<ll> D(N, 0);
    for(auto &d : D){
        cin>>d;
    }
    answer(N, D);

    return 0;
}
