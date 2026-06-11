#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N;
ll A[100000];
ll allXOR = 0;
ll ans = 0;

signed main(){
    cin >> N;
    rep(i, N) cin >> A[i];

    rep(i, N) allXOR ^= A[i];

    int k = 0;
    rep(i, 60){
        if((allXOR>>59-i)&1) ans += 1LL<<59-i;
        else{
            for(int j=k; j<N; j++){
                if((A[j]>>59-i)&1){
                    swap(A[k], A[j]);
                    break;
                }
            }
            if((A[k]>>59-i)&1){
                ans += 1LL<<60-i;
                for(int j=0; j<N; j++){
                    if(j == k) continue;
                    if((A[j]>>59-i)&1) A[j] ^= A[k];
                }
                k++;
            }
            else{
                int cnt = 0;
                rep(j, N){
                    cnt += (A[j]>>59-i)&1;
                }
                if(cnt%2) ans += 1LL<<60-i;
            }
        }
    }
    cout << ans << endl;
}