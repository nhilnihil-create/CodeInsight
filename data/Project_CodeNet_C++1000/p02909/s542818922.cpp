#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    string s;
    cin>>s;
    string wet[]={"Sunny","Cloudy","Rainy"};
    rep(i,3) if(wet[i]==s) cout<<wet[(i+1)%3]<<endl;
    return 0;
}