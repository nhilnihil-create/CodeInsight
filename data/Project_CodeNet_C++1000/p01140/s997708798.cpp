#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,M;
    cin >> N >> M;
    while(N){
        vector<int> Haccum(N+1),Waccum(M+1);
        rep(i,1,N+1){
            int h;
            cin >> h;
            Haccum[i] = Haccum[i-1] + h;
        }
        rep(i,1,M+1){
            int w;
            cin >> w;
            Waccum[i] = Waccum[i-1] + w;
        }
        map<int,int> mp;
        rep(i,0,M){
            rep(j,i+1,M+1){
                mp[Waccum[j] - Waccum[i]]++;
                //cout << i << " " << j << " " << Waccum[j] - Waccum[i] << endl;
            }
        }
        ll cnt = 0;
        rep(i,0,N){
            rep(j,i+1,N+1){
                int num = Haccum[j] - Haccum[i];
                cnt += mp[num];
            }
        }
        cout << cnt << endl;
        cin >> N >> M;
    }
}
