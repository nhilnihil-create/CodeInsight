#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
//MACROS
#define _crt_secure_no_warnings
#define FREEELO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define MAX 1000001
#define MOD 1000000007
#define ALPHABET 128
#define loop(i, n) for (int i = 1; i <= (n); i++)
#define loop0(i, n) for (int i = 0; i < (n); i++)
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> llll;
typedef pair<int, int> ii;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef unordered_set<int> usi;
typedef unordered_multiset<int> usmi;

int main(){
    FREEELO
    string s; cin >> s;
    int sum = 0;
    for (int i = 0; i < sz(s); i++){
        sum += (s[i] - '0');
    }
    cout << (sum % 9 == 0 ? "Yes" : "No") << endl;
}
