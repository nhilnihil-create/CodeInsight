#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;


int main(){
    int H,W,N;
    cin >> H >> W >> N;
    int count = 0;
    int mx,mn;
    mx = max(H,W);
    mn = min(H,W);
    int ans;
    
    for(int i = 1;i <= mn;i++){
        ans = mx*i;
        count++;
        if(ans >= N){
            break;
        }
    }
    cout << count << endl;

    
}
