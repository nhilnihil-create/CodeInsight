#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i<=n ; i++)
#define vi vector<int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())

//const int MOD = 1000000007;
//const int INF = 1<<30;
using namespace std;



int main(){
    
    int n,m;
    cin >> n >> m;
    
    int table[n+10][m+10];
    //初期化
    rep(i,n+10) rep(j,m+10) table[i][j] = 0;
    
    //入力と合計
    rep1(i,n){
        rep1(j,m){
            cin >> table[i][j];
            table[i][m+1] += table[i][j];
            table[n+1][j] += table[i][j];
        }
    }
    
    //全合計
    rep1(i,n) table[n+1][m+1] += table[i][m+1];
    
    //表示
    rep1(i,n+1){
        rep1(j,m) cout << table[i][j] <<" ";
        //cout << endl;
        cout << table[i][m+1] << endl;
    }
    
    
}







