#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
    
    if(A[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> cnt(3, 0);
    ll ans = 1;
    ll MOD = 1e9+7;
    for(int i=0; i<N; i++){
        int match = 0;
        // cout << i << " " << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;

        for(int j=0; j<3; j++){
            if(cnt[j] == A[i]){
                if(match == 0){
                    cnt[j]++;
                }
                match++;
            }
        }
        if(match == 0){
            cout << 0 << endl;
            return 0;
        }else{
            ans = (ans * match)%MOD;
        }
    }
    cout << ans << endl;
}
