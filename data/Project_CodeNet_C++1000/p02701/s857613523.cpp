#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int t;
    cin>>t;

    map<string,int> m;
    int ans=0;

    while(t--) {
        string s;
        cin>>s;

        if(m.find(s)==m.end()) {
            m[s]=1;
            ans++;
        }
    }

    map<string,int>::iterator it;

    //for(it=m.begin();it!=m.end();it++) {
    //    cout<<"key: "<<it->first<<' '<<"value: "<<it->second<<endl;
    //}
    cout<<ans<<endl;

}


