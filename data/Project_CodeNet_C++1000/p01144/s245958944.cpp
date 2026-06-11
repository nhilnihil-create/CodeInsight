#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,M;
    cin >> N >> M;
    while(N){
        vector<pair<int,int> > V(N);
        rep(i,0,N){
            int a,b;
            cin >> a >> b;
            V[i] = P(b,a);
        }
        sort(V.rbegin(), V.rend());
        ll sum = 0;
        rep(i,0,N){
            if(V[i].second < M){
                int tmp = V[i].second;
                V[i].second = 0;
                M -= tmp;
            }else{
                V[i].second -= M;
                M = 0;
            }
            sum += V[i].first * V[i].second;
        }
        cout << sum << endl;
        cin >> N >> M;
    }
}
