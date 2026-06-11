#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin>>N;
    vector<ll> A(N);
    for(ll i=0;i<N;i++){
        cin>>A.at(i);
    }
    ll sum = 0;
    ll tmp = 0;
    for(ll i=0;i<N;i++){
        tmp = max(A.at(i),tmp);
        if(tmp>A.at(i)){
            sum += tmp-A.at(i);
        }
    }
    cout<<sum<<endl;
}