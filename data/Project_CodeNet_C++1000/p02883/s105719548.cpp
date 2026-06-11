#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;
struct eat{
    ll time; ll cost; ll amount;
};

int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> A(N,0);  
    vector<ll> F(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i]
    ;}
    for(ll i=0;i<N;i++){
        cin>>F[i]
    ;}
    //Aは大きい順Fは小さい順
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    reverse(A.begin(), A.end());
    vector<eat> eats(N);
    for(ll i=0;i<N;i++){
        eats[i]=eat{A[i]*F[i],A[i],F[i]}
    ;}

    ll L=-1,R=INF;
    while(L+1<R){
        ll m=(L+R)/2;
        //K2は全員時間m以下にするために必要な修行
        ll K2=0;
        for(ll i=0;i<N;i++){
            if(m<eats[i].time){
                K2+=(eats[i].time-m)/eats[i].amount;
                if((eats[i].time-m)%eats[i].amount!=0)K2++;
            }
        ;}
        if(K2<=K){R=m;}
        else{L=m;}
    }
    cout<<R<<endl;


    return 0;
}
