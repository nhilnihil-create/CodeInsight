#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
    int x;
    cin >> x;
    int kyu = 8;
    x -= 400;
    while(x >= 200) x -= 200, --kyu;
    cout << kyu << endl;
    return 0;
}