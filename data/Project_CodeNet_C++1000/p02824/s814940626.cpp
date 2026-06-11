#include<stdio.h>
#include<algorithm>
#include<vector>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MN = 1e5 + 1;

int N, M, V, P;
int A[MN], B[MN];

bool check(int p) {
    for(int i = 0; i < N; i++) B[i] = A[i];

    ll total_points = (ll)M * V;
    auto give = [&](int i, int amount) {
        ll v = min(total_points, (ll)min(amount, M - (B[i] - A[i])));
        B[i] += v;
        total_points -= v;
    };
    give(p, M);
    int free = P - 1;
    for(int i = N-1; i >= 0 && free > 0; i--) {
        if(i == p) continue;
        give(i, M);
        free--;
    }
    for (int i = 0; i < N; i++) {
        if (i == p) continue;
        give(i, max(0, B[p] - B[i]));
    }
    if (total_points > 0) return false;
    int larger_count = 0;
    for(int i = 0; i < N; i++) {
        if (B[i] > B[p]) larger_count++;
    }
    return larger_count < P;
}

int main() {
    scanf("%d%d%d%d", &N, &M, &V, &P);
    for(int i = 0; i < N; i++)  scanf("%d", &A[i]);
    sort(A, A+N);
    int left = 0, right = N-1, mid, ans;
    while(left <= right) {
        mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    printf("%d\n", N - ans);
    return 0;
}