#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int n;

void solve(string s, char Max){
    if(s.size() == n) cout << s << endl;
    else{
        for(char c = 'a'; c <= Max; c ++) solve(s+c,(c == Max ? char(Max+1):Max));
    }

}

int main() {
    cin >> n;
    solve("a",'b');
}