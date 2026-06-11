#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    vector<vector<ll> > sum(n);
    vector<vector<ll> > ss(n);
    vector<vector<ll> > lg(n,vector<ll>(n,0));

    ll ans = -1000000001;

    for(int i = 0; i < n; i++){
        int pos = i;
        ll cnt = 0;
        ll p_ans = -1000000001;
        ss[i].push_back(0);
        sum[i].push_back(0);
        while(true){
            pos = p[pos];
            if(lg[i][pos] == 1) break;
            ss[i].push_back(c[pos]+ss[i][cnt]);
            cnt++;
            p_ans = max(p_ans, ss[i][cnt]);
            sum[i].push_back(p_ans);
            if(cnt == k) break;
            lg[i][pos] = 1;
        }
        if(k > cnt && ss[i][cnt] > 0){
            ll calc = (k/cnt) * ss[i][cnt];
            if(k%cnt == 0){
                if(sum[i][cnt] > ss[i][cnt]){
                    calc -= ss[i][cnt];
                    calc += sum[i][cnt];
                }
            } else {
                calc += sum[i][k%cnt];
            }
            p_ans = max(p_ans, calc);
        }
        ans = max(ans, p_ans);
    }

    cout << ans << endl;

    return 0;
}