#include <bits/stdc++.h>


typedef long long ll;

using namespace std;


const ll mod=1000000007;

int  main(){

    string s;
    cin>>s;

    int n=s.size();

    reverse(s.begin(),s.end());

    vector<int> vec(2019,0);

    ll t=1;
    ll k=0;
    ++vec[0];

    for(int i=0;i<n;++i){
        k=(((s[i]-'0')*t)+k)%2019;
        ++vec[k];
        t=(t*10)%2019;
    }


    ll ans=0;


    for(int i=0;i<2019;++i){
        if(vec[i]>1){
            ans+=(vec[i]*(vec[i]-1))/2;
        }
    }
  
cout<<ans<<endl;


   
}

