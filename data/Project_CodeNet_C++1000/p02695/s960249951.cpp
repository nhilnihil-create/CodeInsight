#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int ans = 0;
vector<int> a(50, 0), b(50, 0), c(50, 0), d(50, 0);

bool jd(vector<int> A, int qidx){
    if(a[qidx] >= A.size() || b[qidx] >= A.size()) return false;
    if(A[b[qidx]] - A[a[qidx]] == c[qidx]) return true;
    return false;
}

void dfs(int idx, vector<int> A){
    //printf("idx %d\n", idx);
    for(int i = 0; i < idx; i++){
        //printf("%d ", A[i]);
    }
    //printf("\n");
    if(idx >= n){
        //printf("END\n");
        int point = 0;
        for(int i = 0; i < q; i++){
            point += jd(A, i) ? d[i] : 0;
        }
        //printf("point %d\n", point);
        if(ans < point) ans = point;
        return;
    }
    for(int i = (idx>0) ? A[idx-1] : 1; i <= m; i++){
        A[idx] = i;
        dfs(idx+1, A);
    }
}

int main(){
    cin >> n >> m >> q;
    cin.ignore();
    int ta, tb, tc, td;
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];
        --b[i];
        cin.ignore();
    }

    vector<int> A(10, 0);
    dfs(0, A);

    cout << ans << endl;
    return 0;
}