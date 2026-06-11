
    #include <bits/stdc++.h>
    #define rep(i,a,b) for(int i=(a);i<(b);i++)
    #define per(i,a,b) for(int i=(a);i>(b);i--)
    typedef long long ll;
    using namespace std;

    typedef double dd;

    int main(){
         ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    ll x=0;
    for(int i=0;i<s.size();i++){
        x+=(s[i]-'0');
    }
    if(x%9==0){cout<<"Yes"; return 0;}
    else{cout<<"No"; return 0;}
    cout<<x;


        return 0;
    }
