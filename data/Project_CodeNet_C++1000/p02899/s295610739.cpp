#include <bits/stdc++.h>
using namespace std;

struct Data{
    int pos;
    long long val;

    bool operator<(const Data& right) const {
        return val == right.val ? pos < right.pos : val < right.val;
    }
};

void solve(long long N, std::vector<long long> A){
    vector<Data> data(N);
    for(int i = 0; i < N; ++i){
        data[i].pos = i+1;
        data[i].val = A[i];
    }
    sort(data.begin(), data.end());
    for(int i = 0; i < N-1; ++i){
        cout << data[i].pos << " ";
    }
    cout << data[N-1].pos << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
