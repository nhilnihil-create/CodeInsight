#include<bits/stdc++.h>
#define endl  "\n"
#define ll long long
#define PI acos(-1.0)
#define test cout<<"\n****\n"
#define precise fixed(cout);cout<<setprecision(12)
#define fast  ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using  namespace  std;

set<ll> vec;
int main(){

    fast;
    ll n;
    cin>>n;

    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        vec.insert(temp);
    }
    
    if(vec.size()==n){
        cout<<"YES";
    } else{
        cout<<"NO";
    }
    
    return 0;
}
