#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int MOD = 1e9+7;
const int N = 5*1e5;



int main(){
    AC
    string s, t;
    cin>>s>>t;
    if(t.substr(0, s.size()) == s)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}