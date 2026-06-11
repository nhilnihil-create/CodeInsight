#include<iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    for (int hi = 0; hi < h; hi++) {
        for (int wi = 0; wi < w; wi++) {
        int cur = (hi < b) ^ (wi < a);
        cout << cur;
        }
        cout << '\n';
    }
    
}