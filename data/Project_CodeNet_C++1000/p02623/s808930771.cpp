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

int main(){
    int N, M;
    LL K;
    cin >> N >> M >> K;
    vector<LL> sumA(N), sumB(M);
    LL A=0;
    LL B=0;
    LL tmp = 0;
    REP(i,N){
        cin >> tmp;
        A += tmp;
        sumA[i] = A;
    }

    REP(i,M){
        cin >> tmp;
        B += tmp;
        sumB[i] = B;
    }

    int max_ans = 0; 
    int j = M;
    FOR(i, 0, N + 1){
        LL Aval;
        if(i==0){Aval = 0;}
        else{Aval = sumA[i-1];}

        LL r = K - Aval;
        if(r < 0){break;}

        while(j != 0 && sumB[j-1] > r){
            j--;
        }

        chmax(max_ans, (i+j));
    }

    cout << max_ans << endl;
    return 0;
}