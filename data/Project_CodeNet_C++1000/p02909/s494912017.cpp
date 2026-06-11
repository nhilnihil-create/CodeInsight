#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


signed main(){
    FAST;

    string s;
    cin>>s;
    if(s=="Sunny") cout<<"Cloudy";
    else if(s=="Cloudy") cout<<"Rainy";
    else if(s=="Rainy") cout<<"Sunny";
}
