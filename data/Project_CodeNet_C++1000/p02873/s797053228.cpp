#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MN = 5e5 + 1;

char eq[MN];

int N;
int A[MN];
bool memo[MN];
int f(int i) {
    if(memo[i]) return A[i];
    memo[i] = true;
    if(i > 0 && eq[i-1] == '<') {
        A[i] = max(A[i], f(i-1) + 1);
    }
    if(i < N-1 && eq[i] == '>') {
        A[i] = max(A[i], f(i+1) + 1);
    }
    return A[i];
}

int main() {
    scanf("%s", eq);
    N = strlen(eq) + 1;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += f(i);
    }
    printf("%lld\n", ans);
    return 0;
}