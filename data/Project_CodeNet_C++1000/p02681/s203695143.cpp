#include <bits/stdc++.h>
#define rep( i, n ) for (ll i = 0; i < ( ll )(n); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > P;
typedef tuple<int, int, int> T;



int main(){
    string s,t;
    cin>>s>>t;
    for(int i =0;i<s.size();i++){
        if(s[i]!=t[i]) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";

}