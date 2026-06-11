#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 

int main(){
    int n, m ;
    cin >> n >> m ;
    vector<int> h (n) ;
    rep(i, n) cin >> h[i] ; 
    vector<int> ans (n, 1) ;
    rep(i, m){
        int a, b ;
        cin >> a >> b ;
        a-- ; b-- ;
        if(h[a] > h[b]){
            ans[b] = 0 ;
        }
        else if (h[a] < h[b]){
            ans[a] = 0 ;
        }
        else {
            ans[a] = 0 ;
            ans[b] = 0 ;
        }
    }
    int num = 0;
    rep(i, n){
        num += ans[i] ;
    }
    cout << num << endl ;
}