#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n, k;
    cin >> n >> k;
    if(k > (n - 1) * (n - 2) / 2){
        cout << -1 << endl;
    }
    else{
        int m = (n * (n - 1) / 2) - k;
        cout << m << endl;
        for(int i = 1; i <= n-1; i++){
            // ab.push(P(i, n));
            cout << i << " " << n << endl;
        }
        queue<P> ab;
        for(int i = 1; i <= n-1; i++){
            for(int j = i + 1; j <= n-1; j++){
                ab.push(P(i, j));
            }
        }
        for(int i = 0; i < ((n - 1) * (n - 2) / 2) - k; i++){
            cout << ab.front().first << " " << ab.front().second << endl;
            ab.pop();
        }
    }
    return 0;
}