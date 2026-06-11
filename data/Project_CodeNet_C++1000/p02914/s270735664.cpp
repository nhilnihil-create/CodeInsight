#include <bits/stdc++.h>
using namespace std;

int nth_bit(int64_t num, int n){
    return (num >> n) & 1;
}

int64_t msb(int64_t v){
  v = v | (v >>  1);
  v = v | (v >>  2);
  v = v | (v >>  4);
  v = v | (v >>  8);
  v = v | (v >> 16);
  v = v | (v >> 32);
  return v ^ (v >> 1);
}

int main(){
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int64_t ans1 = 0;
    for(int d=0; d<60; d++){
        int num = 0;
        for(int64_t a : A) num += nth_bit(a, d);
        if(num%2){
            ans1 += 1LL<<d;
            for(int64_t& a : A) if(nth_bit(a, d)) a -= 1LL<<d;
        }
    }

    vector<int64_t> V;
    for(int64_t a : A){
        for(int64_t v : V) if(msb(v)&a) a ^= v;
        if(a > 0){
            for(int64_t& v : V) if(msb(a)&v) v ^= a;
            V.push_back(a);
            sort(V.rbegin(), V.rend());
        }
    }

    int64_t ans2 = 0;
    for(int64_t v : V) ans2 ^= v;
    int64_t ans = ans1 + 2*ans2;
    cout << ans << endl;
}
