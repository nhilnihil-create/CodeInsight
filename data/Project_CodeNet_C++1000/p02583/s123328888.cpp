#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <map>
#include <unordered_map>
#include <bitset>

#define _crt_secure_no_warnings
#define FREEELO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F3F3F3F3F
#define MAX 300001
#define ALPHABET 128
#define loop(i, n) for (int i = 1; i <= (n); i++)
#define loop0(i, n) for (int i = 0; i < (n); i++)
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll, ll> llll;
typedef pair<int, int> ii;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    loop0(i, n) cin >> a[i];
    int cnt = 0;
    loop0(i, n){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if (a[i] == a[j] || a[j] == a[k] || a[i] == a[k]) continue;
                if (a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[j] + a[k] > a[i]) cnt++;
            }
        }
    }
    cout << cnt << endl;
}