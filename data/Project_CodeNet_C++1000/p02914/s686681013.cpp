#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),cnt(60);
    ll x = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        x ^= A[i];
    }
    for(int i=0;i<N;i++) A[i] &= ~x;
    int r = 0;
    for(int j=59;j>=0;j--){
        bool ok = false;
        for(int i=r;i<N;i++){
            if(A[i]&(1LL<<j)){
                swap(A[i],A[r]);
                ok = true;
                break;
            }
        }
        if(ok){
            for(int i=0;i<N;i++){
                if((i!=r) && (A[i]&(1LL<<j))) A[i] ^= A[r];
            }
            r++;
        }
    }
    ll ans = 0;
    for(int i=0;i<N;i++) ans = max(ans,ans^A[i]);
    cout << 2*ans+x << endl;
}
