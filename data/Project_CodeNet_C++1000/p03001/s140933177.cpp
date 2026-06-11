#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    cout << (double)w*h/2 << endl;
    if(x*2==w && y*2==h){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}