#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 100000007;

int N,M,Q;
int a[50], b[50], c[50], d[50];

int ans = 0;

void dfs(int digit,int num,vector<int> X){
    if (digit == N){
        int tmp = 0;
        for (int i = 0;i < Q;i++){
            if (X[b[i]] - X[a[i]] == c[i]) tmp += d[i];
        }
        ans = max(ans,tmp);
    }
    else {
        for (int i = num; i < M + 1; i++) {
            vector<int> Y = X;
            Y.push_back(i);
            dfs(digit + 1, i,Y);
        }
    }
}

int main() {
    cin >> N >> M >> Q;
    for (int i = 0;i < Q;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;b[i]--;
    }
    vector<int> X;
    dfs(0,1,X);
    cout << ans << endl;
}