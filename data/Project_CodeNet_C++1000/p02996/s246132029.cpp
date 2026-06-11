#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v[i]=make_pair(b,a);
    }
    sort(v.begin(),v.end());
    ll t=0;
    for(int i=0;i<n;i++){
        if(v[i].first>=v[i].second+t){
            t+=v[i].second;
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}