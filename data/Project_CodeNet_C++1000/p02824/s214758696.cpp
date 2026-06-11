#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int A[100005];
int B[100005];
long long prefixSum[100005];

long long sum(int a, int b){
    return prefixSum[b]-prefixSum[a-1];
}

int main(){
    int N, M, V, P;
    scanf("%d%d%d%d", &N, &M, &V, &P);

    for(int i = 1; i <= N; i ++){
        scanf("%d", &A[i]);
        B[i] = A[i];
    }

    sort(A+1, A+(1+N));
    sort(B+1, B+(1+N));
    reverse(A+1, A+(1+N));

    prefixSum[0] = 0;
    for(int i = 1; i <= N; i ++){
        prefixSum[i] = prefixSum[i-1] + A[i];
    }

    int ans = 0;
    int indx = -1;
    for(int i = 1; i <= N; i ++){
        if(A[i] >= A[P]){
            // all such problems have a chance
            ans ++;
        }else{
            indx = i;
            break;
        }
    }

    if(ans == N){
        printf("%d", N);
        return 0;
    }

    long long maxVotes = (long long)(V-1)*M; // best case always to vote for yourself

    for(int i = 1; i <= N; i ++){
        //printf("A[%d]=%d\n", i, A[i]);
    }

    for(int i = indx; i <= N; i ++){
        //printf("A[%d]=%d\n", i, A[i]);

        if(A[i] + M < A[P]){break;}

        // It's best to increase the number of votes of those in the top P-1
        long long votesCnt1 = (long long)(P-1)*M;

        long long cutoff = A[i]+M;

        long long votesCnt2 = cutoff*(i-P) - sum(P, i-1);
        long long votesCnt3 = (long long)(N-i)*M;

        //printf("votesCnt1=%lld votesCnt2=%lld votesCnt3=%lld\n", votesCnt1, votesCnt2, votesCnt3);

        long long curVotes = votesCnt1+votesCnt2+votesCnt3;
        if(curVotes >= maxVotes){
            ans ++;
        }
    }

    printf("%d", ans);
    return 0;
}
