#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {
    double w,h,x,y; cin >> w >> h >> x >> y;
    double s3 = w*h/2;
    if(w/2 == x && h/2 == y)cout << s3 << " " << 1;
    else cout << s3 <<" " << 0;


    return 0;
}









