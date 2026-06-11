#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n;string s;
    cin >> n >> s;
    int count_r=0,count_w=0;
    REP(i,n){
        if(s[i]=='R')count_r++;
        else count_w++;
    }
    int count_r2=count_r;
    REP(i,count_r){
        if(s[i]=='R'){
            count_r2--;
        }
    }
    COUT(min({count_r,count_w,count_r2}));
}