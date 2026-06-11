#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
//using fs = unordered_set;
//#define fs set//unordered_set

struct UnionF {
    vector<ll> S;
    
    UnionF(ll a){
        S=vector<ll>(a);
        for(ll i=0;i<a;i++)S[i]=i;
    }

    ll FFi(ll i){
        if(S[i]==i)return i;
        S[i]=FFi(S[i]);
        return S[i];
    }

    void marge(ll a,ll b){
        ll aa=FFi(a),bb=FFi(b);
        if(aa==bb)return;
        ll mms = (aa<bb)?aa:bb;
        S[aa]=mms;S[bb]=mms;
    }
    
    bool equalU(ll a,ll b){return (FFi(S[a])==FFi(S[b]));}
    
};

int main() {
    ll N,Q;
    cin >> N >> Q;
    UnionF U(N);
    while(Q){
        ll sub1,sub2,sub3;
        
        cin >> sub1 >> sub2 >> sub3;
        
        if(sub1==0)U.marge(sub2, sub3);
        else {
            if(U.equalU(sub2, sub3))cout << 1 << endl;
            else cout << 0 << endl;
        }
        
        Q--;
    }
    
    
}
