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
int N,D; cin>>N>>D;
int X[N][D];
for(int i=0;i<N;i++){
    for(int j=0;j<D;j++){
    cin>>X[i][j];
    }
}
int ans=0;
for(int i=0;i<N-1;i++){
    for(int k=i+1;k<N;k++){
        double tmp=0;
        for(int j=0;j<D;j++){
        tmp+=(X[i][j]-X[k][j])*(X[i][j]-X[k][j]);
        }
    
         int tmp2=sqrt(tmp);
        if(tmp2*tmp2==tmp){
            ans++;
            }       

    
    }
}
cout<<ans<<endl;
}