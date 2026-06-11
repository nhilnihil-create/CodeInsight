#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int H, N;
    cin >> H >> N;
    int sum = 0;
    rep(i, N){
        int a;
        cin >> a;
        sum += a;
    }
    if(sum >= H) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}