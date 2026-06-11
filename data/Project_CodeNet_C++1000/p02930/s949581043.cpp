#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;

// int MOD = 998244353;
int MOD = 1000000007;

int a[500][500] = {0};

void solve(int l,int r,int d){
    if(abs(l-r) == 1)return;
    int mid = (l+r)/2;
    for(int i = l;i < mid;i++){
        for(int j = mid;j < r;j++){
            a[i][j] = a[j][i] = d;
        }
    }
    solve(l,mid,d+1);
    solve(mid,r,d+1);
    return;
}

signed main(){
    
    ll n;
    cin >> n;
    solve(0,n,1);
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://jsc2019-qual.contest.atcoder.jp/tasks/jsc2019_qual_a
// rm -r -f test;oj dl https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a
// rm -r -f test;oj dl http://abc125.contest.atcoder.jp/tasks/abc125_a
