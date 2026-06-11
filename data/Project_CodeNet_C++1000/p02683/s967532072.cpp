/*
      author : Nishikawa
      created: 09.08.2020 17:15:21
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

int INF = 1e8;

int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<vector<int>> a(n,vector<int>(m));
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    int minf = INF;
    int pat=1;
    for(int i=0; i<n; i++) pat*=2;
    for(int i=1; i<pat; i++){
        vector<int> now(m);
        int c_sum=0;
        int cnt = i;
        for(int j=0; j<n; j++){
            if(cnt&1){
                c_sum+=c[j];
                for(int k=0; k<m; k++){
                    now[k] += a[j][k];
                }
            }
            cnt>>=1;
        }
        bool check=true;
        for(int j=0; j<m; j++){
            if(now[j]<x){
                check = false;
                break;
            }
        }
        if(check) minf=min(minf,c_sum);    
    }
    if(minf!=INF) cout << minf << endl;
    else cout << "-1" << endl;
    return 0;
}