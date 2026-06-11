#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MAXN = 301;

int main(){
    int N, K; cin >> N >> K;
    int MAX = ((N-1)*(N-2))/2;
    if(K > ((N-1) * (N-2)) / 2){
        cout << -1 << endl;
        return 0;
    }
    if(N == 2){
        if(K == 1) cout << -1 << endl;
        else if(K == 0) {cout << 1 << endl; cout << 1 << " " << 2 << endl;}
        return 0;
    }
    cout << N-1+MAX-K << endl;
    //この時点で(N-1)*(N-2) / 2こ
    for(int i = 1; i < N; i++) cout << i << " " << N << endl;;
    //あとMAX-Kこ消す
    int cnt = 0;
    if(cnt==MAX-K) return 0;
    for(int i = 1; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            cout << i << " " << j << endl;
            cnt++;
            if(cnt==MAX-K) return 0;
        }
    }
}
