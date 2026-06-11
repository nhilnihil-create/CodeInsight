#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W,N;
    cin >> H >> W >> N;
    int ans = (max(H,W) + N - 1)/max(H,W);
    cout << ans << endl;
}