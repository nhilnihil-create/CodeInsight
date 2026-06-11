
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

ll a[200005];
map<ll,ll> b;

int main(){
    ll n;
    cin >> n;

    rep(i,n){
        cin >> a[i];
        a[i]--;
        b[a[i]]++;
    }
    //計算を効率化するためにbaseを作る
    ll base=0;
    for(auto item:b){
        base += ((item.second)*(item.second-1))/2;
    }

    for(int i=0; i<n; i++){
        ll num=a[i];
        //baseとの差はnC2-n-1C2
        cout << base - (b[num]*(b[num]-1)/2)+((b[num]-1)*(b[num]-2)/2) << endl;
    }
}