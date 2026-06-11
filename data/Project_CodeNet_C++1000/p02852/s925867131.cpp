#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

string s;
int n, m;
int dp[100010];

void debug(bool x){
    cout << (x ? "true" : "false") << endl;
}

bool can(int i, int k, int d){
    if (i + d >= n) return 1;
    int cont = 0;
    int best = -1;
    for (int j=1; j<=d; j++){
        if (s[i+j] == '0') best = j;
    }
    if (best == -1) return 0;
    return dp[i + best] <= k;
    for (; i<n; ){
        best = -1;
        for (int j=m; j>=1; j--){
            if (i + j >= n || s[i+j] == '0'){
                best = i+j;
                break;
            }
        }
        if (best == -1) return 0;
        i = best;
        cont++;
    }
    return cont <= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    int tam = 1;
    vector<int> optimal;
    for (int i=n; i>0;){
        int best = -1;
        for (int j=m; j>0; j--){
            if (i - j < 0 || s[i-j] == '0'){
                best = i-j;
                if (i - j < 0) best = 0;
                break;
            }
        }
        if (best == -1){
            cout << "-1\n";
            return 0;
        }
        dp[best] = tam++;
        optimal.push_back(best);
        i = best;
    }
    for (int i=0; i<n; i++){
        if (dp[i] != 0) continue;
        dp[i] = dp[i-1];
    }
    tam--;

    /*
    for (int i=1; i<=3; i++){
        debug(can(0, ))
    }
    */

    int cont = 0;
    vector<int> ans;
    for (int i=0; i<n;){
        int l = 1, r = m, best = -1;
        while(l <= r){
            int mid = (l+r)>>1;
            if (can(i, tam-cont-1, mid)){
                best = mid;
                r = mid-1;
            } else l = mid+1;
        }
        ans.push_back(best);
        i += best;
        cont++;
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
}