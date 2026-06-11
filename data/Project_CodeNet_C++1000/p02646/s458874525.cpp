#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

main(){
    ll a,b,v,w,T;
    cin>>a>>v>>b>>w>>T;
    if(v<=w) cout<<"NO";
    else{
        if(abs(a-b) <= (T*(v-w))) cout<<"YES";
        else cout<<"NO";
    }
}