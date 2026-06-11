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
ll N,K; cin>>N>>K;
vi A(N,1);
REP(i,K){
    int d=0;
    cin>>d;
    for(int j=0;j<d;j++){
        int tmp=0;
        cin>>tmp;
        A.at(tmp-1)=0;
  
    }
}
int ans=0;
REP(i,N){
    ans+=A.at(i);
}
cout<<ans<<endl;
}