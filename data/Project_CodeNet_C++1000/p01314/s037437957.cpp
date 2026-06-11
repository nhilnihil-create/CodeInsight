#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
int func(int N){
    int cnt = 0;
    rep(i,1,N){
        int sum = 0;
        for(int j = i;sum < N;j++)sum += j;
        if(sum == N){
            cnt++;
        }
    }
    return cnt;
}
main(){
    int N;
    cin >> N;
    while(N){
        cout << func(N) << endl;
        cin >> N;
    }
}
