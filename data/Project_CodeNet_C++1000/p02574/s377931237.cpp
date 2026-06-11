//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

typedef long long              ll;
typedef long double            ld;
typedef pair<int, int>         pi;
typedef vector<int>            vi;
typedef vector<pair<int, int>> vpi;

#define pb       push_back
#define all(x)   begin(x), end(x)
#define sz(x)    (int)(x).size()
#define ff       first
#define ss       second
#define mp       make_pair
#define lb       lower_bound
#define ub       upper_bound
#define tcase()  int t; cin >> t; while(t--)

const int MOD = 1e9 + 7; // 998244353;
const int MX  = 2e5 + 5;
const ll  INF = 1e18;
const ld  PI  = acos((ld) -1);

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

vi primes(1000002, 0);
bool flag = true;

void primefactor(int x){

    if(flag == false) return;

    for(int i = 1; i * i <= x; i++){

        if(x % i == 0){
            primes[i]++;

            if(primes[x] > 1 && x != 1) flag = false;

            if(i != (x / i)){
                primes[x / i]++;

                if(primes[x / i] > 1 && (x / i) != 1) flag = false;
            }
        }
    }
}


int main(){

    setIO();

    int n;
    cin >> n;

    vi arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        primefactor(arr[i]);
    }

    for(int i = 2; i < 1000002; i++){

        if(primes[i] > 1) flag = false;
    }

    if(flag){
        cout << "pairwise coprime";
        return 0;
    }

    int gcd = arr[0];

    for(int i = 0; i < n; i++){

        gcd = __gcd(gcd, arr[i]);
    }

    if(gcd == 1){
        cout << "setwise coprime";
        return 0;
    }

    cout << "not coprime";
}
