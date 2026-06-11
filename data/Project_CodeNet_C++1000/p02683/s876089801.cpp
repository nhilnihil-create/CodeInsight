#define _GLIBCXX_DEBUG
#define MIN_MAX 1200001
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(void){
    int n, m, x;
    cin >> n >> m >> x;
    vi C(n);
    vvi A(n, vi(m));
    for(int i=0; i<n; i++){
        cin >> C[i];
        for(int &a : A[i]) cin >> a;
    }
    int min = MIN_MAX;
    for(int bit=0; bit<1<<n; bit++){
        int sumC = 0;
        vi sumA(m);
        for(int i=0; i<n; i++)if(bit & 1<<i){
            sumC += C[i];
            for(int j=0; j<m; j++) sumA[j] += A[i][j];
        }
        bool suc = true;
        for(int &a : sumA)if(a<x){suc = false; break;}
        if(suc && sumC < min) min = sumC;
    }
    if(min < MIN_MAX) cout << min << '\n';
    else cout << -1 << '\n';
    return 0;
}