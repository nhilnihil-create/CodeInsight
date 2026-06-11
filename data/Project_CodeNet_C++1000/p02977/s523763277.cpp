#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int bit = __builtin_popcount(n);
    if(bit == 1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        int m = n;
        if(m % 2 == 0)
            m--;
        vector<int> g;
        for(int i = 1;i < 3;i++){
            cout << i << " " << i + 1 << endl;
            cout << n + i << " " << n + i + 1 << endl;
        }
        g.push_back(n + 2);
        cout << 3 << " " << n + 1 << endl;
        g.push_back(3);
        for(int i = 4;i <= m;i += 2){
            cout << n + 1 << " " << i << endl;
            cout << i << " " << i + 1 << endl;
            cout << n + 1 << " " << n + i + 1 << endl;
            cout << n + i + 1 << " " << n + i << endl;
            g.push_back(i);
            g.push_back(n + i + 1);
        }
        if(n % 2 == 0){
            for(int i = 2;i < n;i++){
                int to = n ^ 1 ^ i;
                if(to < n){
                    cout << n << " " << g[i - 2] << endl;
                    cout << n + n << " " << g[to - 2] << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
