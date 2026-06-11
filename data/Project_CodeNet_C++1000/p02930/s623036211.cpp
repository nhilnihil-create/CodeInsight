#include <iostream>

using namespace std;

int ans[500][500];
//int m = 0;

void calc(int n, int s, int m){
    if(s == 1) return;
    for(int i = n; i < n+s/2; i++){
        for(int j = n+s/2; j <n+s; j++){
            ans[i][j] = m;
        }
    }
    calc(n, s/2, m+1);
    calc(n+s/2, s-s/2, m+1);
}

int main(){
    int N;
    cin >> N;
    calc(0, N, 1);
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            cout << ans[i][j];
            if(j == N-1) cout << endl;
            else cout << ' ';
        }
    }
}