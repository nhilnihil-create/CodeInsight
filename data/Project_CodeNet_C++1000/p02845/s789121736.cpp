#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string,ll>;
using Map = map<char,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    ll next1=0,next2=0,next3=0;
    ll ans=1;
    for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        if(a==next1){
            if(next1!=next2){}
            else if(next2!=next3){ans*=2;}
            else{ans*=3;}
            next1++;
        }
        else if(a==next2){
            if(next2!=next3){}
            else{ans*=2;}
            next2++;
        }
        else if(a==next3){next3++;}
        else {cout<<0<<endl; return 0;}
        ans%=MOD;
    ;}
    cout<<ans<<endl;
return 0;
}
