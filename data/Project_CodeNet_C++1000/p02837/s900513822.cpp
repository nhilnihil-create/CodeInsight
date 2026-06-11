#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384

using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    vector<vector<P>> A(N);
    rep(i, N){
        int a;
        cin >> a;
        
        rep(j, a){
            int x, y;
            cin >> x >> y;
            A[i].push_back(P(--x, y));
        }
    }
    
    int ans=0;
    for(int bit=0; bit<(1<<N); bit++){
        bool ok=true;
        int res=0;
        for(int i=0; i<N; i++){
            if(bit>>i&1){
                for(int j=0; j<A[i].size(); j++){
                    int x = A[i][j].first;
                    int y = A[i][j].second;
                    
                    if(y==1&&!(bit>>x&1)) ok=false;
                    if(y==0&&(bit>>x&1)) ok=false;
                }
                if(ok) res+=1;
            }
        }
        if(ok) ans = max(ans, res);
    }
    
    cout << ans << endl;
    
    return 0;
}
