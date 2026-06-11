#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;

int N;
long long A[200005];
long long B[200005];

/*
1 6
2 5
3 9
8 12
*/

ii cntAtLeast(long long k){
    long long ans1 = 0;
    long long ans2 = 0;
    for(int i = 0; i < N; i ++){
        if(k >= B[i]){ans1 ++;}
        if(k >= A[i]){ans2 ++;}
    }

    return ii(ans1, ans2);
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%lld%lld", &A[i], &B[i]);
    }

    long long lo = 0;
    long long hi = 1000000000;
    while(lo < hi){
        long long temp = (lo+hi)>>1;
        if(cntAtLeast(temp).second >= (N+1)/2){
            hi = temp;
        }else{
            lo = temp+1;
        }
    }

    long long loMedian = lo;

    lo = 0;
    hi = 1000000000;
    while(lo < hi){
        long long temp = (lo+hi)>>1;
        if(cntAtLeast(temp).first >= (N+2)/2){
            hi = temp;
        }else{
            lo = temp+1;
        }
    }

    long long hiMedian = lo;

    //printf("debug: %lld %lld\n", loMedian, hiMedian);

    if(N%2 == 1){
        printf("%lld", hiMedian-loMedian+1);
        return 0;
    }else{
        long long ans = hiMedian-loMedian+1;

        long long lo = 0;
        long long hi = 1000000000;
        while(lo < hi){
            long long temp = (lo+hi)>>1;
            if(cntAtLeast(temp).second >= (N+2)/2){
                hi = temp;
            }else{
                lo = temp+1;
            }
        }

        long long loMedian2 = lo;

        lo = 0;
        hi = 1000000000;
        while(lo < hi){
            long long temp = (lo+hi)>>1;
            if(cntAtLeast(temp).first >= (N+1)/2){
                hi = temp;
            }else{
                lo = temp+1;
            }
        }

        long long hiMedian2 = lo;

        //printf("debug2: %lld %lld\n", loMedian2, hiMedian2);

        loMedian *= 2;
        loMedian2 *= 2;
        hiMedian *= 2;
        hiMedian2 *= 2;

        long long finalLoMedian = (loMedian+loMedian2)/2;
        long long finalHiMedian = (hiMedian+hiMedian2)/2;

        printf("%lld\n", finalHiMedian-finalLoMedian+1);
        return 0;
    }
    return 0;
}
