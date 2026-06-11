#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;


struct Lowmath {
    ll Sline;
    vector<ll> S;
    
    Lowmath(ll a){
        Sline = a;
        S=vector<ll>(a+1,0);
    }
    void addset(ll a,ll b){
        a+=1;
            do{
                S[a]+=b;
                
            }while((a+=a&(-a))<=Sline);
    }
        
    ll sumset0(ll i){
        ll sum=0;
        do{
        sum+=S[i];
        }while(i-=i&(-i));
        return sum;
    }
    
    ll sumset(ll l,ll r){
        return sumset0(r) - sumset0(l);
        
    }
    
    
};

string BN(ll a){
    string S="";
    S.push_back((a&1) + '0');
    while (a >>=1) {
        S.push_back((a&1) + '0');
    }
    reverse(S.begin(), S.end());
    return S;
}

int main() {
    ll N,Q;
    cin >> N >> Q;
    Lowmath A(N);
    for(ll i=0;i<A.Sline;i++){
        ll s1;
        cin >> s1;
        A.addset(i, s1);
    }
    
    while(Q){
        ll s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        if(s1==0)A.addset(s2, s3);
        else{
            cout << A.sumset(s2, s3) << endl;
        }
        
        
        Q--;
    }
    
    
}
