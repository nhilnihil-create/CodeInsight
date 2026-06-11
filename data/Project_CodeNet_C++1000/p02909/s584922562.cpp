#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?

string s;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    if(s=="Sunny")cout<<"Cloudy";
    else if(s=="Cloudy")cout<<"Rainy";
    else cout<<"Sunny";

}
