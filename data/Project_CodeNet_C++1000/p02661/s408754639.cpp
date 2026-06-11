#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

int main(){
    int n;
    cin>>n;
    vector<ll>a,b;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    if(!(n%2)){
        cout<<-a[n/2]-a[n/2-1]+b[n/2]+b[n/2-1]+1<<endl;
    }else{
        cout<<-a[(n+1)/2-1]+b[(n+1)/2-1]+1<<endl;
    }
    
    return 0;
}