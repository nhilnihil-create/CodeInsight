#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int h,w,m;
    cin >> h >> w >> m;
    vector<pair<int,int>> t;
    vector<long>a(h),b(w),e(h),f(w);
    rep(i,m){
        int c,d;
        cin >> c >> d;
        c--;d--;
        t.emplace_back(c,d);
        a[c]++;
        b[d]++;
    }
    long maxh=0,maxw=0,k=0,l=0;
    rep(i,h) maxh = max(maxh,a[i]);
    rep(i,w) maxw = max(maxw,b[i]);
    rep(i,h){
        if(a[i]==maxh){
            e[i]=1;
            k++;
        } 
    }
    rep(i,w){
        if(b[i]==maxw){
            f[i]=1;
            l++;
        }
    }
    long cnt = l*k;
    for(auto i:t){
        if(e[i.first]&&f[i.second]) cnt--;
    }
    if(cnt==0) cout << maxh+maxw-1 << endl;
    else cout << maxw+maxh << endl;
}