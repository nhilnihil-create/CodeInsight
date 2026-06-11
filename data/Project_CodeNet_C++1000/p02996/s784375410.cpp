#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll=long long;

int main(){
    ll N;
    cin>>N;
    vector<pair<ll,ll> > works(N);
    for(ll i=0;i<N;i++){
        ll a,b;
        cin>>a>>b;
        works[i]=make_pair(b,a);
    }
    sort(works.begin(),works.end());
    ll task_sum=0;
    for(ll i=0;i<N;i++){
        task_sum+=works[i].second;
        if(task_sum>works[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}