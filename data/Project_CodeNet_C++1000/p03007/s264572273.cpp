#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;



int main(){
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    deque<ll> plus;
    deque<ll> minus;
    ll counterp=0,counterm=0;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        if(A[i]>=0)counterp++;
        else counterm++;
    ;}
    if(counterp==0){
        sort(A.begin(), A.end());
        for(ll i=0;i<N-1;i++){
            minus.emplace_back(A[i]);
        ;}
        plus.emplace_back(A[N-1]);
    }
    else if(counterm==0){
        sort(A.begin(), A.end());
        for(ll i=1;i<N;i++){
            plus.emplace_back(A[i]);
        ;}
        minus.emplace_back(A[0]);
    }
    else {
        for(ll i=0;i<N;i++){
            if(A[i]>=0)plus.emplace_back(A[i]);
            else minus.emplace_back(A[i]);
        ;}  
    }
    ll M=0;
    for(ll i=0;i<plus.size();i++){
        M+=plus[i]
    ;}
    for(ll i=0;i<minus.size();i++){
        M-=minus[i]
    ;}
    cout<<M<<endl;
    for(ll i=0;i<N-1;i++){
        if(plus.size()>minus.size()){
            ll x=plus[0];
            ll y=minus[0];
            plus.pop_front();
            minus.pop_front();
            minus.emplace_back(y-x);
            cout<<y<<" "<<x<<endl;
        }
        else if(plus.size()<=minus.size()){
            ll x=plus[0];
            ll y=minus[0];
            plus.pop_front();
            minus.pop_front();
            plus.emplace_back(x-y);
            cout<<x<<" "<<y<<endl;
        }
    ;}



    return 0;
}
