/*
    ->->->->-> Vora Mahammasasim <-<-<-<-<-
*/
#include<bits/stdc++.h>
#define Quick std :: ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MOD 1e7+7;
using namespace std;





signed main(){

    Quick;
    string s;
    cin>>s;
    if(s[s.size()-1]!= 's') cout<<s+'s';
    else cout<<s+"es";
    return 0;
}
