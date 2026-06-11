#include <bits/stdc++.h>
using namespace std;

int64_t msb(int64_t v){
  v = v | (v >>  1);
  v = v | (v >>  2);
  v = v | (v >>  4);
  v = v | (v >>  8);
  v = v | (v >> 16);
  v = v | (v >> 32);
  return v ^ (v >> 1);
}

int nth_bit(int64_t num, int n){
    return (num >> n) & 1;
}

int main(){
    int N;
    cin >> N;
    int cnt[60] = {0};
    vector<int64_t> V(N);
    vector<int64_t> A;
    for(int i=0; i<N; i++){
        cin >> V[i];
        for(int k=0; k<60; k++) cnt[k] += nth_bit(V[i], k);
    }
    for(int k=0; k<60; k++) if(cnt[k]%2) for(int i=0; i<N; i++) if(nth_bit(V[i], k)) V[i] -= 1LL<<k;
    for(int64_t v : V){
        for(int64_t a : A) if(msb(a) & v) v ^= a;
        if(v > 0){
            A.push_back(v);
            sort(A.rbegin(), A.rend());
        }
    }

    int64_t ans = 0, v = 0, use = 0;
    for(int k=59; k>=0; k--){
        if(cnt[k]%2){
            ans += 1LL<<k;
        }else{
            int64_t v2 = use | (1LL<<k);
            for(auto a : A) if(((v^a)&v2) == v2) v ^= a;
            if((v&v2) == v2){
                ans += 2LL<<k;
                use |= 1LL<<k;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
