#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

  ll a , v , b , w ,t;
    cin>>a>>v>>b>>w>>t;
    ll d = abs(a-b);
    if(v<=w) 
      cout<<"NO\n";
    else{
        if(t*(v-w)>=d) 
          cout<<"YES\n";
        else
         cout<<"NO\n";
    }

  return 0;
}
