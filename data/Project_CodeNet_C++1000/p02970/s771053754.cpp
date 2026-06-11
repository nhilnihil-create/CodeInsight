#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n, d;
    cin >> n >> d;
    int cnt = 0;
    while(n > 0){
        n -= (d * 2 + 1);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}