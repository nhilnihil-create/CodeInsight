#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

const int mod = 1e9 + 7;
const long long INF = 1LL<<60;
using ll = long long;
using P = pair<int,int>;

// mid番目の箇所は採用されるかどうかを判定する
bool isOK(long long mid, vector<long long> &a, long long n, long long m, long long v, long long p){
    
    if (n-p <= mid) return true; // はじめから上位p以内であれば採用される
    
    else if (a[mid] + m < a[n-p]) return false; // mを足されても上位p以内に入れない
    
    
    // otherwise
    long long mv = m * v;
    long long res = 0;
    
    // mid番目の値が, ちょうど上位p位になれるかどうかを判定する
    rep(j, n){
        
        if (a[j] <= a[mid]) res += m; //a[mid]自身以下であれば無視して良いから
        else if (n-p+1 <= j) res += m; // 上位p-1個は無視して良いから
        else res += (a[mid] + m - a[j]);
    }
    
    if (res >= mv) return true;
    else return false;
}

int main(){
    long long n, m, v, p;
    cin >> n >> m >> v >> p;
    
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    
    //int ans;
    
    // binary_serachによりokの位置の下限を求める
    // ans = n - ok;
    
    //binary_serachによりokの位置の下限を求める
    long long ng = -1; //条件を満たさない
    long long ok = n;  //条件を満たす
    
    while(abs(ok - ng) > 1){
        long long mid = (ng + ok) / 2;
        
        if (isOK(mid, a, n, m, v, p)) ok = mid;
        else ng = mid;
        
       // cout << ng << " " << ok << endl;
    }
    
    long long ans = n - ok;
    cout << ans << endl;

}