#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    ll w,h,x,y; cin >> w >> h >> x >> y;
    bool t=0;
    if(w/2==x && (w+1)/2==x && h/2==y && (h+1)/2==y){
        t=1;
    }
    
    double s=(double)w*(double)h/2;
    // if(w%2==1 & h%2==1) s+=0.5;
    cout << s << " " << t << endl;
}