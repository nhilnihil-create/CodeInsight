#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
const long long INF = 100000000;
using namespace std;

int main(){
    int e;
    while(cin >> e, e){
        long long ans = INF;
        for(long long y = 0; y * y <= 1000000; y++){
            for(long long z = 0; z * z <= 1000000; z++){
                if(e - y * y - z * z * z < 0) continue;
                ans = min(ans, y + z + (e - y * y - z * z * z));
            }
        }
        cout << ans << endl;
    }
}