#include <bits/stdc++.h>
using namespace std;

struct cood
{
    int x, y;
} A[205];

bool myComp(cood a, cood b)
{
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i].x >> A[i].y;
    sort(A, A + N, myComp);
    for(int i = 0; i < N; i++)
        A[N + i] = A[i];
    double ans = 0;
    for(int i = 0; i < N; i++)
    {
        long long x = 0, y = 0;
        for(int j = i; j < i + N; j++)
        {
            x += A[j].x;
            y += A[j].y;
            ans = max(ans, sqrt(pow(x, 2) + pow(y, 2)));
        }
    }
    printf("%.15f\n", ans);
}