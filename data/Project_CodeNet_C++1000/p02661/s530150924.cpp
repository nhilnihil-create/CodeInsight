#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=2e5+10;

typedef long long int ll;

ll A[MAXN],B[MAXN];

int main(){
    int N;
    scanf("%d",&N);

    for(int i=1;i<=N;i++) scanf("%lld%lld",A+i,B+i);

    sort(A+1,A+N+1);
    sort(B+1,B+N+1);

    if (N%2){
        printf("%lld\n",B[(N+1)/2]-A[(N+1)/2]+1);
    }else{
        printf("%lld\n",B[N/2]+B[N/2+1]-A[N/2]-A[N/2+1]+1);
    }

    return 0;
}