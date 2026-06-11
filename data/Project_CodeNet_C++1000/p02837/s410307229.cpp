//
// author  : Abhishek
//
#include <bits/stdc++.h>

#define ll long long
#define db double
#define deb(x) cout<<#x<<": "<<x<<"\n"
#define all(x) x.begin(),x.end()
#define fo(i, n) for(i=0 ; i<n ; i++)
#define Fo(i, k, n) for(i=k ; i<n ; i++)

using namespace std;

const ll mod = 1000000007;
const ll N = 300005;  // array size
const ll inf = 10000000000000000;


void print(vector<ll> v) {
    ll i;
    fo(i, v.size())cout << v[i] << " ";
    cout << "\n";
}

vector<ll> read(ll n) {
    ll i;
    vector<ll> arr(n, 0);
    fo(i, n)cin >> arr[i];
    return arr;
}

vector<ll> read(ll n, ll k) {
    ll i;
    vector<ll> arr(n + k, 0);
    Fo(i, k, n + k)cin >> arr[i];
    return arr;
}

bool isEven(ll n) {
    return n % 2 == 0;
}

bool isOdd(ll n) {
    return n % 2 != 0;
}


void solve() {
    ll t;
    cin >> (t);
    while (t--) {

        ll i, j, k, n, m, p, q, x, y, a, b, l, r;


    }
}


ll power(ll x, ll n, ll m) {
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    ll ans;
    if (isEven(n)) {
        ll smallAns = power(x, n / 2, m);
        ans = (smallAns * smallAns) % m;
    } else {
        ll smallAns = power(x, n - 1, m);
        ans = x;
        ans = (ans * smallAns) % m;
    }
    // for negative values also
    return (ans + m) % m;

}

class Per {
public:
    ll x;
    ll y;

};

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, k, n, m, p, q, x, y, a, b, l, r;

    cin >> n;
    vector<Per> arr[n];
    fo(i, n) {
        cin >> k;
        while (k--) {
            Per temp;
            cin >> x >> y;
            x--;
            temp.x = x;
            temp.y = y;
            arr[i].push_back(temp);
        }

    }

//    fo(i, n) {
//        fo(j, arr[i].size()) {
//            cout << arr[i][j].x << " " << arr[i][j].y << "\n";
//        }
//    }


    ll mask;

    ll ans = 0;

    for (mask = 0; mask <= (1 << n) - 1; mask++) {

        ll ct = 0;

        fo(i, n) {
            if (mask & (1 << i)) {
                ct++;
            }
        }

        bool ok = true;

        fo(i, n) {
            if (mask & (1 << i)) {
//                if (mask == 3) {
//                    deb(i);
//                }
                fo(j, arr[i].size()) {
                    ll next = arr[i][j].x;
                    ll verd = arr[i][j].y;

                    ll save = (mask & (1 << next));

                    if(save == 0 && verd == 0){

                    } else if(save!=0 && verd !=0){

                    } else{
                        ok = false;
                    }
//                    if ((ll) (mask & (1 << next)) != verd) {
//                        ok = false;
//                    }
//                    if (mask == 3) {
//                        deb(next);
//                        deb(ok);
//                        deb(mask);
//                        deb((mask & (1 << next)));
//                        deb(verd);
//                    }
                }
            }
        }

//        if (mask == 3) {
//            deb(ok);
//        }

        if (ok) {
            ans = max(ans, ct);
        }


    }

    cout << ans;

    return 0;
}


