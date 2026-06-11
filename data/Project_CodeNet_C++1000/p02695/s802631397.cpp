#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}


int N, M, Q;
vector<int> a, b, c, d;
int ans=0;

// 全探索するものの転換
// もとの数列を全探索する
void dfs(vector<int> A){
    if(A.size()==N){
        int tmpAns = 0;
        REP(i, Q){
            if(A[b[i]-1] == A[a[i]-1] + c[i]){
                tmpAns += d[i];
            }   
        }
        chmax(ans, tmpAns);
        return;
    }

    int val;
    if(A.size()==0){
        val = 1;
    }else{
        val = A.back();
    }
    A.push_back(val);
    while(A.back()<=M){
        dfs(A);
        A.back()++;
    }
}

int main(){
    cin >> N >> M >> Q;
    a = b = c = d = vector<int>(Q);
    REP(i,Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    dfs(vector<int>(0));
    cout << ans << endl;
    return 0;
}