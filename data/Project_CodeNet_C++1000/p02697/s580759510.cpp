#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using Tu = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;

    for(ll i=0;i<M;i++){
        if(1+i<M-i){
            cout<<1+i<<" "<<M-i<<endl;
        }
        else break;
    ;}
    for(ll i=0;i<M;i++){
        if(M+1+i<2*M+1-i){
            cout<<M+1+i<<" "<<2*M+1-i<<endl;
        }
        else break;
    ;}



    return 0;
}
