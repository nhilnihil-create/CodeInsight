#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD 1000000007



int main(){
    int n;
    cin>>n;

    vector<pair<ll,ll>> sch(n);

    ll x,l;
    for(int i=0;i<n;i++){
        cin>>x>>l;
        sch.at(i).second=x-l;
        sch.at(i).first=x+l;
    }

    sort(sch.begin(),sch.end());


    ll cd=sch.at(0).first,co=1;
    for(int i=0;i<n;i++){
        if(sch.at(i).second<cd)continue;
        cd = sch.at(i).first;
        co++;
    }

    cout<<co<<endl;


}