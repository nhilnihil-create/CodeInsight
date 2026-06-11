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

int n;
int arr[MX];
bool NotOk[1000002];

int main(){

    setIO();

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++){

        if(i != 0 && arr[i] == arr[i - 1]){
            NotOk[arr[i]] = true;
            continue;
        }

        for(int j = 2 * arr[i]; j <= 1000000; j += arr[i]) NotOk[j] = true;
    }

    int Ans = 0;

    for(int i = 0; i < n; i++){

        if(!NotOk[arr[i]]) Ans++;
    }

    cout << Ans;
}
