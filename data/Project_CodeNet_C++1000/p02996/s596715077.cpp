#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<pair<ll,ll> > vec(N);
    rep(i,N){
        cin >> vec[i].second >> vec[i].first;
    }
    sort(all(vec));
    ll deadline = 0;
    ll workinghours = 0;
    bool possible = true;
    rep(i,N){
        workinghours += vec[i].second;
        deadline = vec[i].first;
        if (deadline < workinghours) possible = false;
    }
    if (possible) cout << "Yes" << endl;
    else cout << "No" << endl;
}

