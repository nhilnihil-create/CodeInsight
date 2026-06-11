#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    printf("%Lf ",(long double)w*h/2.0);
    if(2*x-w==0 && 2*y-h==0){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
    return 0;
}