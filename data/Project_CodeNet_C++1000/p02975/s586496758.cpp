#include<stdio.h>
#include<algorithm>
#include<vector>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MN = 1e5 + 1;
int A[MN];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    sort(A, A+N);
    if (N % 3 == 0) {
        puts(
            (A[0] == A[N/3 - 1]) &&
            (A[N/3] == A[2*N/3 - 1]) &&
            (A[2*N/3] == A[N-1]) &&
            ((A[0]^A[N/3]^A[2*N/3]) == 0) ? "Yes" : "No"
        );
    }
    else {
        puts((A[0] == A[N-1]) && (A[0] == 0) ? "Yes" : "No");
    }
    return 0;
}