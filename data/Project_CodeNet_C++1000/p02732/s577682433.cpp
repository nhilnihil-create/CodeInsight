#include<bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A.at(i);
    vector<int> cnt(N+1);
    vector<int64_t> comb(N+1);
    for(int i=0; i<N; i++) cnt.at(A.at(i))++;
    for(int i=0; i<N+1; i++){
        int64_t cnti = cnt.at(i); 
        comb.at(i) = cnti * (cnti - 1);
        if(comb.at(i) != 0) comb.at(i) /= 2;
    }
    int64_t sum = 0;
    for(int i=0; i<N+1; i++) sum += comb.at(i);
    for(int i=0; i<N; i++){
        int64_t Ai = A.at(i);
        int64_t local_sum = sum;
        int64_t cnti = cnt.at(Ai);
        int64_t local_comb = (cnti - 1) * (cnti - 2);
        if(local_comb != 0) local_comb /= 2;
        local_sum = local_sum - comb.at(Ai) + local_comb;

        cout << local_sum << endl;
    }
}