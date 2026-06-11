/* Author: Dhruv Rastogi */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<int, int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<int> >
#define vll vector<int>
#define mint map<int,int> 
#define sz(x) (int)x.size()
#define sll set<int>
#define pll pair<int,int>
#define F first
#define S second
const long double PI = acos(-1.0);

const int N = 1e5+5;
int fact[N];
void computefact(){
    fact[0]=1;
    rep(i,1,N){
        fact[i]=(fact[i-1]*i)%hell;
    }
}
void solve(){  
    string s;
    int n;
    cin>>n;
    cin>>s;
    int par=0;
    int pref=0;
    int ways=1;
    rep(i,0,sz(s)){
        if(s[i]=='B' && !par){
            ++pref;
        }
        else if(s[i]=='W' && par){
            ++pref;
        }
        else{
            ways*=pref;
            ways%=hell;
            --pref;
            if(pref<0){
                cout<<0<<endl;
                return;
            }
        }
        par^=1;
    }  
    computefact();
    if(pref!=0){
        cout<<0<<endl;
        return;
    }
    cout<<ways*fact[sz(s)/2]%hell<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}