#include<cstdio>
#include<math.h>

using namespace std;

const int MAX_N = 200000;

int N;
long long d;
long long X[MAX_N], Y[MAX_N];

void solve();

int main(){

    scanf("%d %ld", &N, &d);
    for(int i=0;i<N; i++){
        scanf("%ld %ld", &X[i], &Y[i]);
    }

    solve();

    return 0;
}

void solve(){

    int ans=0;
    for(int i =0;i<N; i++){
        if(X[i]*X[i] + Y[i]*Y[i]<= d*d) {
            ans++;
        }
    }

    printf("%d\n", ans);
}