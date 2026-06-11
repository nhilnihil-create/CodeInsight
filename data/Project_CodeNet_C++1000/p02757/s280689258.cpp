#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    int n, p;
    string s; cin>>n>>p>>s;
    ll ans = 0;
    if(p==2 || p==5){
        for(int i = 0; i<n; i++){
            if((s[i]-'0')%p==0) ans+=i+1;
        }
    }
    else{
        map<int, int> m;
        m[0]++;
        ll po = 1, sum = 0;
        for(int i = n-1; i>=0; i--){
            sum = (sum+(s[i]-'0')*po)%p;
            ans += m[sum];
            m[sum]++;
            po = (10*po)%p;
        }
    }
    cout<<ans<<"\n";
    return 0;
}