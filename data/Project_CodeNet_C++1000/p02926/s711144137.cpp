#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define PI 3.14159265358979323846
ll N;
pll yxv[111];
vector<pair<double, ll>> rv;

double ans;
ll i, j, k;
int main(){
    scanf("%lld",&N);
    fornum(i,0,N){
        ll x,y,xi,yi;
        scanf("%lld%lld", &x, &y);
        yxv[i] = {y, x};
        rv.push_back({atan2(y, x), i});
    }
    sort(rv.begin(), rv.end());
    
    j = 0;
    fornum(i,0,N){
        pll yx = {0,0};

        double lim = atan2(-yxv[rv[i].second].first, -yxv[rv[i].second].second);
        if(lim<0){
            lim += 2 * PI;
        }
        fornum(j, i, 2 * N){
            double r = rv[j % N].first + (j < N ? 0 : 2 * PI);
            ll jj = rv[j % N].second;
            if(r>lim){
                break;
            }
            yx.first += yxv[jj].first;
            yx.second += yxv[jj].second;
            double aa = (double)yx.first * yx.first + (double)yx.second * yx.second;
            if(aa>ans){
                ans = aa;
            }
        }
    }
    printf("%.12lf", sqrt(ans));

    return 0;
}