#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

ll N, D, A, ans=0;
vector<pair<ll, ll>> XH;
vector<ll> C;
//vector<pair<ll, ll>> XH;
//ll X[200000], H[200000];

signed main(){
    cin >> N >> D >> A;
    for(int i=0;i<N;i++) {
        ll X, H;
        cin >> X >> H;
        XH.push_back(make_pair(X, H));
        C.push_back(0);
    }
    sort(XH.begin(), XH.end());
    //for(int i=0;i<N;i++) cout << C[i] << endl;
    for(int i=0;i<N;i++) {
        pair<ll, ll> p = XH[i];
        ll ileft = lower_bound(XH.begin(), XH.end(), make_pair((ll)p.first-2*D, (ll)-1000000000000))-XH.begin();
        ll pre=0;
        if(i) {
            C[i] = C[i-1];
        }
        if(ileft!=i&&i>0) {
            if(ileft>0) pre += C[i-1]-C[ileft-1];
            else pre += C[i-1];
        }
        p.second -= pre*A;
        if(p.second>0){
            if(p.second%A==0) {
                ll addi = p.second/A;
                //cout << C[i] << endl;
                //cout << addi << endl;
                C[i] += addi;
                //cout << C[i] << endl;
                //cout << endl;
            }
            else {
                ll addi = p.second/A;
                //cout << C[i] << endl;
                //cout << addi << endl;
                C[i] += addi+1;
                //cout << C[i] << endl;
                //cout << endl;
            }
        }
    }
    //for(int i=0;i<N;i++) cout << C[i] << endl;
    cout << C.back() << endl;
    return 0;
}