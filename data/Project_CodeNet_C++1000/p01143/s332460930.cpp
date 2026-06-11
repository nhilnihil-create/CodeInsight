#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,M,P;
    cin >> N >> M >> P;
    while(N){
        int cnt = 0,x,all = 0;
        rep(i,0,N){
            cin >> x;
            all += x;
            if(i == (M-1))cnt = x;
        }
        int sum = all * 100;
        sum -= sum * P / 100;
        if(cnt)cout << sum / cnt << endl;
        else   cout << 0 << endl;
        cin >> N >> M >> P;
    }
}
