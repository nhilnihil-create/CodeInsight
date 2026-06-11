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
typedef double lf;
typedef pair<ll, ll> llll;
typedef pair<int, int> ii;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;


int num_of_divs(int n, set<int> &s){
    int cnt = 0;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) {
            cnt++;
            while(n % i == 0) n /= i;
            s.insert(i);
        }
    }
    if (n > 1) s.insert(n), cnt++;
    return cnt;
}

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}
int v[MAX];
int main(){
    FREEELO
    int s_c;
    int n; cin >> n;
    int cnt = 0;
    set<int> s;
    loop(i, n){
        cin >> v[i];
        if (i == 1) s_c = v[i];
        s_c = gcd(s_c, v[i]);
    }
    if (s_c != 1) {
        cout << "not coprime" << endl;
        return 0;
    }
    int p_c = 1;
    loop(i, n){
        cnt += num_of_divs(v[i], s);
        if (cnt != sz(s)) {
            p_c = 0;
            break;
        }
    }
    if (p_c) cout << "pairwise coprime" << endl;
    else cout << "setwise coprime" << endl;

}