#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll INF=2000000000;
ll Sum=1;
ll MAX_N=100100;
ll K=0;
vector<vector<ll>> Child(MAX_N, vector<ll>(0));
//vector<vector<ll>> Parent(MAX_N, vector<ll>(0));

void Calc(ll X){
    if(Sum==0){
        return;
    }
    if(X==0){
            ll ChildNum=Child.at(0).size();
        ll i=0;
        while(ChildNum>0){
            Sum*=(K-1-i);//ここが１
            Sum%=MOD;
            ChildNum --;
            i ++;
        }
        ChildNum=Child.at(0).size();
        for(ll j=0; j<ChildNum; j++){
            Calc(Child.at(0).at(j));
        }
        return;
    }
    if(Child.at(X).size()==0){
        return;
    }
    ll ChildNum=Child.at(X).size();
    ll i=0;
    while(ChildNum>0){
        Sum*=(K-2-i);
        Sum%=MOD;
        ChildNum --;
        i ++;
    }
    ChildNum=Child.at(X).size();
    for(ll j=0; j<ChildNum; j++){
        Calc(Child.at(X).at(j));
    }
    return;
}


int main(){
    ll N;
    cin>>N>>K;
    vector<ll> A(N-1), B(N-1);
    vector<vector<ll>> Way(N, vector<ll>(0));
    for(ll i=0; i<N-1; i++){
        cin>>A[i]>>B[i];
        A[i]--;
        B[i]--;
        Way.at(A[i]).push_back(B[i]);
        Way.at(B[i]).push_back(A[i]);
    }
    queue<ll> Q;
    vector<bool> Use(N, false);
    Use[0]=true;
    Q.push(0);
    while(!(Q.empty())){
        ll Now=Q.front();
        Q.pop();
        ll Sz=Way.at(Now).size();
        for(ll i=0; i<Sz; i++){
            if(Use[Way[Now][i]]){
                continue;
            }
            Q.push(Way[Now][i]);
            Child.at(Now).push_back(Way[Now][i]);
            Use[Way[Now][i]]=true;
        }
    }



    Sum *= K;
    Calc(0);
    cout<<Sum<<endl;

}