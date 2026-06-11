#include<bits/stdc++.h>
using namespace std;

// ある整数Nを(i*j)で表せた時、i+j-2の最小値?
// sqrt(N)まで見ればよい! -> ループで書いているが、sqrt(N)でとめるので
// O(N)より小さい計算量! 最小値は保持する方法で求める。
// いきなり、数学的に最適解を求めに行くのではない!! 

int main(){
    long long N;
    cin >> N;
    long long ans = N-1; // 解は最悪でも(1,N)には存在するつまり、最大N-1
    int i = 1;
    while (pow(i,2) <= N){
        long long M = N/i;
        if (i*M == N){
            ans = min(ans, M + i - 2);
        }
        i += 1;
    }
    cout << ans << endl;
}