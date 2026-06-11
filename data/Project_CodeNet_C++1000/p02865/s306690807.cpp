#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007;
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    int n;
    cin >> n;
    if(n %2 == 1) cout << n/2 << endl;
    else cout << n/2-1 << endl;
    return 0;
}
