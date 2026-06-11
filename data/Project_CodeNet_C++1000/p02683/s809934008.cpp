#include<iostream>
using namespace std;
int n, m, k;
int book[15][15], C[15];
int OK(int x) {
    //printf("x = %d\n",x);
    for(int j = 1; j <= m; ++j) {
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(x & (1<<i)) ans += book[i+1][j];
        }
        if(ans < k) return -1;
    }
    
    int tot = 0;
    for(int i = 0; i < n; ++i) {
        if(x & (1<<i)) tot += C[i+1]; 
    }
    //printf("tot = %d\n",tot);
    return tot;
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> C[i];
        for(int j = 1; j <= m; ++j)
            cin >> book[i][j];
    }

    int Min = 0x7fffffff;
    for(int i = 0; i < (1<<(n)); ++i) {
        int ans = OK(i);
        if(ans != -1 && ans < Min) Min = ans;
    }
    if(Min != 0x7fffffff)
        cout << Min << '\n';
    else cout << "-1\n";
return 0;
}