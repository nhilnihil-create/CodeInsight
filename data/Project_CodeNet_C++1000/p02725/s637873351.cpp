//
//  main.cpp
//  C - Traveling Salesman around Lake
//
//  Created by 李远铄 on 2020/7/15.
//  Copyright © 2020 李远铄. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;
long K;
long N;
long* A;
long* ans;
int main(int argc, const char * argv[]) {
    scanf("%ld %ld",&K,&N);
    A=(long*)calloc(N, sizeof(long));
    ans=(long*)calloc(N, sizeof(long));
    scanf("%ld",A+0);
    for (long i=1; i<N; i++) {
        scanf("%ld",A+i);
        ans[i-1]=A[i]-A[i-1];
    }
    ans[N-1]=K-A[N-1]+A[0];
    long max=0;
    for (int i=0; i<N; i++) {
        if (max<ans[i]) {
            max=ans[i];
        }
    }
    printf("%ld",K-max);
    return 0;
}
