#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    
    // 2. 出力.
    if(N & 1) printf("%d\n", N / 2);
    else      printf("%d\n",(N - 1) / 2);
    return 0;
    
}