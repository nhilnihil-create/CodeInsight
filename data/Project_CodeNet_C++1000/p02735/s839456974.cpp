#include<stdio.h>
#include<algorithm>
#include<vector>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, M;
char A[100][100+1];
int D[100][100];

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%s", A[i]);
    }
    D[0][0] = A[0][0] == '#';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i+j==0) continue;
            D[i][j] = 1e9;
            if(i > 0) {
                int v = D[i-1][j] + (A[i-1][j] == '.' && A[i][j] == '#');
                D[i][j] = min(D[i][j], v);
            }
            if(j > 0) {
                int v = D[i][j-1] + (A[i][j-1] == '.' && A[i][j] == '#');
                D[i][j] = min(D[i][j], v);
            }
        }
    }
    printf("%d\n", D[N-1][M-1]);
    return 0;
}