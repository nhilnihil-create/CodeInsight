#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=1'000'000'007;
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

void answer(ll A, ll B){
    ll answer = 0;

    ll c;
    c = gcd(A, B);

    ll p = c;
    answer = 1;

    if(p % 2 == 0){
        p /= 2;
        answer++;
        while(p % 2 == 0){
            p /= 2;
        }
    }

    for(ll i=3; i<=sqrt(c); i+=2){
        if(p == 1){
            break;
        }
        debug(i, p);
        if(p % i == 0){
            p /= i;
            debug(i);
            answer++;
            while(p % i == 0){
                p /= i;
            }
        }
    }
    if(p != 1){
        answer++;
    }

    cout<<answer<<endl;

    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    ll A, B;
    cin>>A>>B;
    answer(A, B);

    return 0;
}
