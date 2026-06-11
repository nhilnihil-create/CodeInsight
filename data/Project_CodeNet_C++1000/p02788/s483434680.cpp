#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define ll long long
#define INF 1000000000
#define P std::pair<int,int>
#define LP std::pair<ll,ll>


int main(){
    int n,d,a; std::cin >> n >> d >> a;
    d *= 2;
    std::vector<P> xh(n);
    rep(i,n)
        std::cin >> xh[i].first >> xh[i].second;

    std::sort(xh.begin(), xh.end());
    std::queue<LP> que;
    ll ans=0, dmg=0;
    rep(i,n){
        int x=xh[i].first;
        int h=xh[i].second;
        while(que.size() && que.front().first < x){
            dmg -= que.front().second;
            que.pop();
        }
        h -= dmg;
        if(h > 0){
            ll cnt=(h+a-1)/a;
            ans += cnt;
            ll tmp=cnt*a;
            dmg += tmp;
            que.push(LP(x+d, tmp));
        }
    }
    std::cout << ans << std::endl;
    return 0;
}