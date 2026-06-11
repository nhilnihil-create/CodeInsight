// ※※※ 解答不能 ※※※
// 以下のソースを勉強する.
// E869120氏.
// https://atcoder.jp/contests/jsc2019-qual/submissions/7109342
#include <bits/stdc++.h>
using namespace std;
#pragma warning (disable: 4996)
using LL = long long;
LL mod = 1000000007;
int A[300009];

int main(){
    
    int N;
    char C[210012];
    scanf("%d %s", &N, C);
    string S(C);
    
    if(S[0] == 'W' || S[S.size() - 1] == 'W'){
        printf("%d\n", 0);
        return 0;
    }
    for(int i = 0; i < S.size(); i++){
        if(i == 0) A[i] = 1;
        else if(S[i - 1] != S[i]){
            if(A[i - 1] == 1) A[i] = 1;
            else              A[i] = 0;
        }else{
            if(A[i - 1] == 1) A[i] = 0;
            else              A[i] = 1;
        }
    }
    
    LL dep = 0, ans = 1;
    for(int i = 0; i < S.size(); i++){
        if(A[i] == 1){
            dep++;
        }else{
            ans *= dep;
            ans %= mod;
            dep--;
        }
        if(dep < 0){
            printf("%d\n", 0);
            return 0;
        }
    }
    if(dep != 0){
        printf("%d\n", 0);
        return 0;
    }
    for(LL i = 1; i <= N; i++){
        ans *= i;
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}