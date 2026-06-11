#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N;
string X;
vector<pair<string, ll>> inpt;
ll i, j;
int main(){
    cin >> N;
    fornum(i,0,N){
        string s;
        ll t;
        cin >> s >> t;
        inpt.push_back({s, t});
    }
    cin >> X;

    ll ans = 0;
    for (i = N - 1; i >= 0;--i){
        if(inpt[i].first==X){
            break;
        }
        ans += inpt[i].second;
    }
    cout << ans;
    return 0;
}