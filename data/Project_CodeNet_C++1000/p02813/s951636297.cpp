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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){

    setIO();

    int n;
    cin >> n;

    int arr1[n], arr2[n];

    char a1[n], a2[n];

    for(int i = 0; i < n; i++){
        cin >> a1[i];
        arr1[i] = a1[i] - '0';
    }

    for(int i = 0; i < n; i++){
        cin >> a2[i];
        arr2[i] = a2[i] - '0';
    }

    int myints[n];

    for(int i = 0; i < n; i++) myints[i] = i + 1;

    int cnt1 = 0, cnt2 = 0;

    do {
        int cnt3 = 0;
        for(int i = 0; i < n; i++){
            if(myints[i] == arr1[i]) cnt3++;
        }
        if(cnt3 == n) break;
        cnt1++;
    } while ( std::next_permutation(myints,myints + n) );

    sort(myints, myints + n);

    do {
        int cnt3 = 0;
        for(int i = 0; i < n; i++){
            if(myints[i] == arr2[i]) cnt3++;
        }
        if(cnt3 == n) break;
        cnt2++;
    } while ( std::next_permutation(myints,myints + n) );

    cout << abs(cnt1 - cnt2);
}
