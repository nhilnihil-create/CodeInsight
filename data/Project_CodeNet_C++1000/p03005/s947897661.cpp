#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K;
    scanf("%d%d", &N, &K);

    if(K == 1){printf("0"); return 0;}

    printf("%d", N-K);
}

