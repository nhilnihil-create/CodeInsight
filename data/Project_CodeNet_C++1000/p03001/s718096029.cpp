#include<bits/stdc++.h>
using namespace std;

int main(){
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    cout << (double)w*(double)h/(double)2 << " ";
    if(x*2==w&&y*2==h)cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}