#include <bits/stdc++.h>
#define rep(i,d) for (int i = 0; i < (d); i++);
using namespace std;
using ll = long long;


int main() {
    int h,w,n;
    cin >> h >> w >> n;

    if (h >= w){
        if (n%h == 0){
            cout << n/h << endl;
        }

        else{
            cout << n/h+1 << endl;
        }
    }

    if (h < w){
        if (n%w == 0){
            cout << n/w << endl;
        }

        else{
            cout << n/w+1 << endl;
        }
    }
}