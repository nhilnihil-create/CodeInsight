#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

signed main(){
    int N;
    cin >> N;
    
    string S[N];
    int t[N];
    for(int i=0;i<N;i++){
        cin >> S[i] >> t[i];
    }
    string X;
    cin >> X;
    
    int tmp=0,ans=0;
    for(int i=0;i<N;i++){
        if(tmp>0) ans += t[i];
        if(S[i]==X) tmp++;
    }
    
    cout << ans << endl;
    
    return 0;
}
