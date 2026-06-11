#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int A,B,M;
    cin >> A >> B >> M;
    vector<int> fridge(A);
    vector<int> oven(B);
    vector<pair<int,int> > ticket(M);
    vector<int> price(M);
    rep(i,A){
        cin >> fridge[i];
    }
    rep(i,B){
        cin >> oven[i];
    }
    rep(i,M){
        cin >> ticket[i].first >> ticket[i].second >> price[i];
    }
    int ans = 10000000;
    rep(i,M){
        ans = min(ans, fridge[ticket[i].first - 1] + oven[ticket[i].second - 1] - price[i]);
    }
    sort(all(fridge));
    sort(all(oven));
    ans = min(ans, fridge[0] + oven[0]);
    cout << ans << endl;
}
