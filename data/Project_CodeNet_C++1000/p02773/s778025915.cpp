#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    ll n;
    cin>>n;

    map<string, ll> dict;

    map<string,ll>::iterator it;
    ll mx=0;
    while(n--) {
        string s;
        cin>>s;

        if(dict.find(s)!=dict.end()) {
            dict[s]++;
        }
        else {
            dict[s]=1;
        }
        mx=max(mx, dict[s]);
    }

    //for(it=dict.begin();it!=dict.end();it++) { 
    //    cout<<"key: "<<it->first<<endl;
    //    cout<<"value: "<< it->second<<endl;
    //    cout<<"__________"<<endl;
    //}

    for(it=dict.begin();it!=dict.end();it++) {
        if(it->second==mx) {
            cout<<it->first<<endl;
        }
    }
}


