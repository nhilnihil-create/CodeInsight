#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int h,a;
    cin >> h >> a;
    int res =h/a;
    if (h%a != 0) res++;
    cout << res;
    return 0;
}

