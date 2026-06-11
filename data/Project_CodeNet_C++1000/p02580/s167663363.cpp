#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using vi = vector<int>;
using vv = vector<vi>;
//const int MOD = 1000000007;
//const int MOD = 998244353;
const ll INF = 1001001001001;

int main(){
    int H, W, M;
    cin >> H >> W >> M;
    vector<P> vH(H), vW(W);
    set<P> vB;
    rep(i,H){
        vH[i].first = 0;
        vH[i].second = i;
    }
    rep(i,W){
        vW[i].first = 0;
        vW[i].second = i;
    }
    
    while(M){
        M--;
        int i,j; cin>>i>>j; i--;j--;
        vH[i].first++;
        vW[j].first++;
        vB.insert(P(i,j));
    }
    sort(rall(vH));
    sort(rall(vW));
    
    int nH = vH[0].first;
    int nW = vW[0].first;
    set<int> mH, mW;
    auto itH = &vH[0], itW = &vW[0];
    while((*itH).first == nH){
        mH.insert((*itH).second);
        itH++;
    }
    while((*itW).first == nW){
        mW.insert((*itW).second);
        itW++;
    }
    
    ll count = (ll)mH.size()*mW.size();
    
    if(count>vB.size()){
        cout<< nH+nW <<endl;
        return 0;
    }
    
    for(auto b: vB){
        int h = b.first;
        int w = b.second;
        if(mH.count(h) && mW.count(w))
            count--;
    }
    
    if(!count)
        cout << nH+nW-1 << endl;
    else
        cout << nH+nW << endl;
    return 0;
}