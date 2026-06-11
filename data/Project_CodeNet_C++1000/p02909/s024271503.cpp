#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define endl '\n'
using namespace std;


int main(){
        fast_io
        map<string,string> m;
        m["Sunny"]="Cloudy";
        m["Cloudy"]="Rainy";
        m["Rainy"]="Sunny";
        
        string s; cin>>s;
        cout<<m[s]<<endl;
    return 0;
}

