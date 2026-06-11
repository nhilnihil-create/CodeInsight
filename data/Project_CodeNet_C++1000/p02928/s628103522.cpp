#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    ll N, K; cin >> N >> K;
    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    ll rev1=0;
    
    for(int i = 0; i < N-1; i++){
        ll cnt=0;
        for(int j = i+1; j < N; j++){
            //ll cnt=0;
            if(A[i] > A[j]){
                rev1++;
                //cout << A[i] << " " << A[j] << endl;
                cnt++;
            }
        }
        //cout << i << " A[i] : " << A[i]  << "  : " << cnt << endl;
    }
    sort(A.rbegin(), A.rend());
    ll rev2 = 0;
    for(int i = 0; i < N-1; i++){
        ll cnt=0;
        for(int j = i+1; j < N; j++){
            if(A[i] > A[j]){
                rev2++;
                cnt++;
            }
        }
    }
    
    ll sigma = ((K*(K-1))/2)%MOD;
    //cout << sigma << " " << rev1 << " " << rev2 << endl;
    cout << ((sigma*rev2)%MOD + K*rev1)%MOD  << endl;
}