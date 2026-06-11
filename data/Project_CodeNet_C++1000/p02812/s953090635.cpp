//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pb push_back
using namespace std;
void solve(){
    int n,c=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.length()-2;i++)
    if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
    c++;
    cout<<c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
