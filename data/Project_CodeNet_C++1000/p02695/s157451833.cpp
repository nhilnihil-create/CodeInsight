#include <bits/stdc++.h>

using namespace std;


int n,m,q;
int a[100],b[100],c[100],d[100];
int ans = 0;

void dfs(vector<int> A) {
    if(A.size() == n+1) {
        int counter = 0;
        for(int i = 0; i < q; i++) {
            if(A[b[i]] - A[a[i]] == c[i]) {
                counter += d[i];
            }
        }
        ans = max(ans,counter);
        return;
    }
    A.push_back(A.back());
    while(A.back() <= m) {
        dfs(A);
        A.back()++;
    }
}

int main() {
    cin >> n >> m >> q;
    for(int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    dfs(vector<int>(1,1));
    cout << ans << "\n";
    return 0;
}