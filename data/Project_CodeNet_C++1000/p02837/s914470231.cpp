#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)
#define INF (1LL << 60)

int main(void){
    int n;
    cin >> n;
    int a[n];
    vector<vector<int>> x(n+1,vector<int>(n+1,-1));
    
    rep(i,n){
        cin >> a[i];
        rep(j,a[i]){
            int p,q;
            cin >> p >> q;
            x[i][p-1] = q;
        }
    }
    
    int alina = 0;
    for(int i = 0;i < (1 << n);i++){
        int b[n],gray = 0;
        rep(j,n){
            if(i & (1 << j)){
                b[j] = 1;
                gray++;
            }
            else b[j] = 0;
        }
        
        bool check = true;
        rep(j,n){
            if(i & (1 << j)){
                rep(l,n){
                    if(x[j][l] == -1)continue;
                    
                    if(b[j] == 1){
                        if(x[j][l] != b[l])check = false;
                    }
                }
            }
        }
        
        if(check)alina = max(alina,gray);
    }
    
    cout << alina << endl;
}