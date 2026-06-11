#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H,W,N;
    cin >> H >> W >> N;
    int t = max(H,W);
    cout << (N+t-1)/t << '\n';
    return 0;
}