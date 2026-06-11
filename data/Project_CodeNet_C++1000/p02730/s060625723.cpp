#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define INF 1e12
const int MOD = 1000000007;
typedef pair<ll,ll> P;

bool Palindrome(string s, int n){
    int f =  0;
    bool res = true;
    while(f <= n){
        if(s[f] != s[n]){
            res = false;
            break;
        }
        f++;
        n--;
    }
    return res;
}

int main(void){
    string s,s1,s2;
    int n,n1,n2;
    cin >> s;
    n = s.length();
    n1 = (n - 1) / 2;
    n2 = (n + 3) / 2;
    s1 = s.substr(0, n1);
    s2 = s.substr(n2 - 1);
    if(     Palindrome(s, n - 1) 
        &&  Palindrome(s1, s1.length() - 1)
        &&  Palindrome(s2, s2.length() - 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}