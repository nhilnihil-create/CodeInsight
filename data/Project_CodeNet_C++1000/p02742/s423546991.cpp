#include<cmath>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<algorithm>
#include<list>
#include<cstring>
#include <numeric>

#define ll long long
#define int long long
#define ld long double
#define endl "\n"
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(p) cerr<<#p<<'='<<(p.first)<<" "<<p.second<<endl;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define output(x)   cout << (x ? "YES" : "NO")<<endl;
const ll MOD = 1e9 + 7;
const int N = 'Z'+5;
const int demo = 10;
using namespace std;
const ll cfmod=998244353;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
char button[4]={'L','R','U','D'};

// Ahhiya thi lakhvanu chalu thasse....

signed main() {
    FAST
    int q = 1;
    //cin>>q;
    while (q--) {
        int a,b;
        cin>>a>>b;
        if(a!=1 && b!=1){
            cout<<(a*b+1)/2;
        }
        else{
            cout<<1<<endl;
        }
    }
}