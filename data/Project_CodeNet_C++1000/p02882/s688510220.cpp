#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double l=0, r=M_PI/2;
    while(r-l > 1e-8){
        double mid=l+(r-l)/2;
        double v;
        if(b-a*tan(mid) >= 0){
            v=(a*b-a*a*tan(mid)/2)*a;
        }
        else{
            v=b*b/tan(mid)/2*a;
        }
        if(v <= x) r=mid;
        else l=mid;
    }
    cout << fixed << setprecision(7);
    cout << r*180/M_PI << endl;
    return 0;
}