#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    string s;
    int k;
    cin>>k>>s;

    if(s.size()<=k) {
        cout<<s<<endl;
    }
    else {
        cout<<s.substr(0,k)<<"..."<<endl;
    }
}


