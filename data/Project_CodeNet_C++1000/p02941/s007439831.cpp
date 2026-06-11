#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int A[200005];
int B[200005];

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < N; i ++){
        scanf("%d", &B[i]);
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;

    for(int i = 0; i < N; i ++){
        pq.push(ii(B[i] + B[(i+2)%N], i));
    }

    long long cnt = 0;
    while(!pq.empty()){
        ii temp = pq.top(); pq.pop();

        int val = temp.first;
        int indx = temp.second;

        if(val != B[indx] + B[(indx+2)%N]){continue;}

        /*printf("Current B: ");
        for(int i = 0; i < N; i ++){
            printf("%d ", B[i]);
        }
        printf("\n");*/

        int sum = (B[(indx+2)%N]+B[indx]);
        int times = (B[(indx+1)%N]-A[(indx+1)%N])/sum;

        if(times == 0){continue;}

        B[(indx+1)%N] -= times*sum;

        cnt += times;

        pq.push(ii(B[(indx+N-1)%N]+B[(indx+1)%N], (indx+N-1)%N));
        pq.push(ii(B[(indx+1)%N]+B[(indx+3)%N], (indx+1)%N));
    }

    for(int i = 0; i < N; i ++){
        if(B[i] != A[i]){
            printf("-1");
            return 0;
        }
    }

    printf("%lld\n", cnt);
}
