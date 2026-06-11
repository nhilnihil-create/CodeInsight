#include<bits/stdc++.h>
using namespace std;

template <class T>
using V = vector<T>;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for(int i=m; i<n; i++)

int main(){
    int N;
    cin >> N;
    V<int> P(N);
    rep(i, N) cin >> P.at(i);
    int min = 200000;
    int cnt = 0;
    rep(i, N){
        if(min >= P.at(i)){
            min = P.at(i);
            cnt++;
        } 
    }
    cout << cnt << endl;
}