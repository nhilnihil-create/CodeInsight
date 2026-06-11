#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int m=1e9+7;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio
    vector<string>s={"Sunny","Cloudy","Rainy"};
    string k;
    cin>>k;
    auto it=find(s.begin(),s.end(),k);
    cout<<s[(it-s.begin()+1)%3];
    return 0;
}