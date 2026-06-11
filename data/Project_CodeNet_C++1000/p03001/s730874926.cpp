#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)
#define INF (1LL << 60)
#define itn int

int main(void){
    ll w,h,x,y;
    cin >> w >> h >> x >> y;
    
    int cnt = 0;
    if(h == y*2 && w == x*2)cnt++;
    cout << (double(w) * double(h) / 2) << " " << cnt << endl;
}
