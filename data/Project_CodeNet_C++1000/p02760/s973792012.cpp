#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

v2 a(3, v1(3, 0));
v2 c(3, v1(3, 0));
ll n;
ll b;
void yes(){
    cout << "Yes" << endl;
    exit(0);
}

void no(){
    cout << "No" << endl;
    exit(0);
}

int main(){
    for(ll i = 0;i < 3;i++){
        for(ll j = 0;j < 3;j++){
            cin >> a[i][j];
        }
    }
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll b;
        cin >> b;
        for(ll j = 0;j < 3;j++){
            for(ll k = 0;k < 3;k++){
                if(a[j][k] == b) c[j][k] = 1;
            }
        }
    }
    for(ll i = 0;i < 3;i++){
        ll flag = 1;
        for(ll j = 0;j < 3;j++){
            if(c[i][j] == 0) flag = 0;
        }
        if(flag == 1){
            yes();
        }
    }
    for(ll i = 0;i < 3;i++){
        ll flag = 1;
        for(ll j = 0;j < 3;j++){
            if(c[j][i] == 0) flag = 0;
        }
        if(flag == 1){
            yes();
        }
    }
    ll flag = 1;
    for(ll i = 0;i < 3;i++){
        if(c[i][i] == 0) flag = 0;
    }
    if(flag == 1){
        yes();
    }
    flag = 1;
    for(ll i = 0;i < 3;i++){
        if(c[i][2-i] == 0) flag = 0;
    }
    if(flag == 1){
        yes();
    }
    no();

}
