#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int A[10];
int N,M,Q,a[50],b[50],c[50],d[50];
int ans = 0;

void dfs(int i,const int start){
    if(i==N){
        int total = 0;
        rep(j,Q){
            if(A[b[j]] - A[a[j]] == c[j]){
                total += d[j];
            }
            ans = max(ans,total);
        }
    }else{
        for(int j=start;j<=M;j++){
            A[i] = j;
            dfs(i+1,j);
        }
    }
}

int main(){
    cin >> N >> M >> Q;
    rep(i,Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }
    dfs(0,1);
    cout << ans << endl;
}
