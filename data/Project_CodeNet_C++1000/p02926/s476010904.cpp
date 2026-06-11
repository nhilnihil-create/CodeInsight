#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define bitrep(X,N) for(ll X = 0; X < (1 << (N)); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end() 


using namespace std;

int main(){

    int n;
    cin >> n;
    vector<tuple<double,ll,ll>> v;

    rep(i,n){
        ll tmpx,tmpy;
        cin >> tmpx >> tmpy;

        double angle;

        double tmpd = sqrt((double)(tmpy * tmpy + tmpx * tmpx));

        if(tmpd < 1.0){
            angle = 0.0;
        }else{
            if(tmpy >= 0){
                angle = acos(((double)tmpx) / tmpd);
            }else{
                angle = 2 * PI - acos(((double)tmpx) / tmpd);
            }
        }

        v.pback(make_tuple(angle,tmpx, tmpy));
    }

    sort(ALL(v));

    rep(i,n){
        double tmpa = get<0>(v[i]);
        ll tmpx = get<1>(v[i]);
        ll tmpy = get<2>(v[i]);

        tmpa = tmpa + 2 * PI;

        v.pback(make_tuple(tmpa,tmpx,tmpy));
    }  

    ll bestd = 0;

    for(int l = 0; l < n; l++){
        for(int i = 1; i <= n; i++){
            ll tmpx = 0;
            ll tmpy = 0;

            rep(j,i){
                tmpx += get<1>(v[l + j]);
                tmpy += get<2>(v[l + j]);
            }

            bestd = max(bestd, tmpx * tmpx + tmpy * tmpy);
        }
    }

    double ans = (double)bestd;
    ans = sqrt(ans);

    cout << setprecision(52) << ans << endl;
}