#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main(){
ll N,K,x; cin>>N>>K;
if(N>K){
    x=N%K;
}else{
    x=N;
}
ll ans=0;
while(true){
    ll tmp1,tmp2,tmp3;
    tmp1=x;
    x=abs(x-K);
    tmp2=abs(tmp1-K);
    tmp3=abs(tmp2-K);
    if(tmp1==tmp3){
        ans=min(tmp1,tmp2);
        break;
    }

}
cout<<ans<<endl;
}