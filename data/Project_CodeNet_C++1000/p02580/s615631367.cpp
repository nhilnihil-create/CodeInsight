#include <bits/stdc++.h>

using namespace std;
const int maxn=3e5+111;
vector<int> tg[maxn], tg1[maxn], r, c;
int H, W, M, col[maxn], row[maxn];

bool cmp1(int i, int j){
    return row[i]>row[j];
}

bool cmp2(int i, int j){
    return col[i]>col[j];
}

int main(){
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    scanf("%d%d%d", &H, &W, &M);
    for (int i=1; i<=H; i++) r.push_back(i);
    for (int j=1; j<=W; j++) c.push_back(j);
    int hi, wi;
    for (int i=0; i<M; i++){
        scanf("%d%d", &hi, &wi);
        tg[hi].push_back(wi);
        tg1[wi].push_back(hi);
        col[wi]++; row[hi]++;
    }
    sort(r.begin(), r.end(), cmp1);
    sort(c.begin(), c.end(), cmp2);
    int ans=0;
    int cnt=r[0];
    for (int j=0; j<tg[cnt].size(); j++) col[tg[cnt][j]]--;
    int tmp=0;
    for (int j=1; j<=W; j++) tmp=max(tmp, col[j]);
    for (int j=0; j<tg[cnt].size(); j++) col[tg[cnt][j]]++;
    ans=row[cnt]+tmp;

    cnt=c[0]; tmp=0;
    for (int j=0; j<tg1[cnt].size(); j++) row[tg1[cnt][j]]--;
    for (int j=1; j<=H; j++) tmp=max(tmp, row[j]);
    for (int j=0; j<tg1[cnt].size(); j++) row[tg1[cnt][j]]++;
    ans=max(ans, col[cnt]+tmp);

    printf("%d", ans);
}

