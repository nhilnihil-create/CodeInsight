#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef  long long ll;
typedef unsigned long long ull;
const ll LIM =1e9+7;

template<typename T>
void fin (T a){
    cout<<a<<endl;
    exit(0);
}
template<typename S>
void print(S a){
    cout<<a<<endl;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    string s; cin>>s;
    map<char,int> mp;
    mp['R']=1;
    mp['G']=1;
    mp['B']=1;
    rep(i,n){
        mp[s[i]]++;
    }
    ll ans =1;
    for(auto x:mp){
        ans *= x.second-1;
    }
    for(int gap=1; gap*2<=n+10;gap++){
        for(int p=0;p+2*gap<n;p++){
            int tmp = s[p]+s[p+gap]+s[p+2*gap];
            if(tmp==219)ans--;
        }
    }

    fin(ans);


}
