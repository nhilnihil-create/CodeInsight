#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

const int MAX_N = 60;
pair<int, int> XY[MAX_N];
int N;

int edge_count(int dx, int dy) {
    int res = 0;
    for(int i = 0; i < N; ++i) for(int j = i+1; j < N; ++j) 
        if(XY[j].first - XY[i].first == dx && XY[j].second - XY[i].second == dy) ++res;
    return res;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d %d", &XY[i].first, &XY[i].second);
    sort(XY, XY+N);

    int ans = N;
    for(int i = 0; i < N; ++i) for(int j = i+1; j < N; ++j) 
        ans = min(ans, N - edge_count(XY[j].first - XY[i].first, XY[j].second - XY[i].second));
    
    printf("%d\n", ans);
    return 0;
}