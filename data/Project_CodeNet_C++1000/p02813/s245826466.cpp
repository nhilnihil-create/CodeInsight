#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> P, std::vector<long long> Q){
    vector<long long> numbers(N, 0);
    for(int i = 0; i < N; ++i) numbers[i] = i+1;
    int cnt = 1;
    int a = 0; int b = 0;
    do{
        vector<bool> flag(2, true);
        for(int i = 0; i < N; ++i){
            //cout << numbers[i] << " " << P[i] << " " << Q[i] << endl;
            if(numbers[i] != P[i]) flag[0] = false;
            if(numbers[i] != Q[i]) flag[1] = false;
        }
        if(flag[0]) a = cnt;
        if(flag[1]) b = cnt;
        cnt++;
    }while(next_permutation(numbers.begin(), numbers.end()));
    //cout << a << " " << b << endl;
    cout << abs(a - b) << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&P[i]);
    }
    std::vector<long long> Q(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&Q[i]);
    }
    solve(N, std::move(P), std::move(Q));
    return 0;
}
