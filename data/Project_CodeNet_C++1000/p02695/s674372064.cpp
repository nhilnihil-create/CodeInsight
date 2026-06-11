#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)

int main(){
    int N,M,Q; cin >> N >> M >> Q;
    vector<int> a(Q),b(Q),c(Q),d(Q);
    rep(i,0,Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }

    ll ans = 0;
    for(ll bit=0; bit < (1<<M); ++bit){
        ll sum = 0;
        int p = __builtin_popcount(bit);
        if(p == N){
            vector<int> A;
            rep(i,0,M){
                if(bit & (1<<i)) A.push_back(i+1);
            }
            rep(i,0,Q){
                if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
            }
            ans = max(ans,sum);

        }else if(p < N){
            vector<int> v;
            rep(i,0,M){
                if(bit & (1<<i)) v.push_back(i+1);
            }
            rep(i,0,M){
                if(bit & (1<<i)) v.push_back(i+1);
            }

            vector<int> A(N);
            // 考え得るかぎりのA(N)を作って、sumを全探索
            for(ll mask = 0; mask < (1<<N); ++mask){
                if(__builtin_popcount(mask) == p-1){
                    int x = 0;
                    rep(i,0,N){
                        if(x == p) break;
                        A[i] = v[x];
                        if(mask & (1<<i)) x++; 
                    }
                    rep(i,0,Q){
                        if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
                    }
                    ans = max(ans,sum);
                    sum = 0;
                }
            }
            
        }
    }
    cout << ans << endl;
}