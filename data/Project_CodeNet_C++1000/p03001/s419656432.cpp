#include <bits/stdc++.h>
using namespace std ;
int main(){
    int W,H,x,y;
    cin >> W >> H >> x >>y;
    double Ans = double(W)*double(H) / 2;
    cout << Ans << endl;
    if(2*x==W&&2*y==H)cout << 1 << endl;
    else cout << 0 << endl;

}
