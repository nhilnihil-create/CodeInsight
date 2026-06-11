#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int N;
vector<long long> x,y;

int solve(){
    if(N == 1)return 1;
    
    int res = N;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N; j++){
            if(i == j)continue;
            long long dx = x[j] - x[i], dy = y[j] - y[i];
            
            int sub = 0;
            for(int i2 = 0; i2 < N; i2++){
                for(int j2 = 0; j2 < N;j2++){
                    if(j2 == i2)continue;
                    if(dx == x[j2] - x[i2] && dy == y[j2] - y[i2])++sub;
                }
            }
            res = min(res,N-sub);
        }
    }
    return res;
}







int main(){
    cin >> N;
    x.resize(N),y.resize(N);
    for(int i = 0; i < N;i++) cin >> x[i] >> y[i];
    cout << solve() << endl;
}