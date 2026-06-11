#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    cin>>n>>p;
    string s;
    cin>>s;

    if(10%p == 0){
        long long ans = 0;
        for(int i = 0; i < (int)s.length(); i++ ){
              if((s[i]-'0')%p == 0) ans+=(i+1);
        }
        cout<<ans;
        return 0;
    }

    map<int,int> mp;
    mp[0] = 1;
    int pp = 1;
    int t = 0;
    long long ans = 0;
    for(int i = n-1; i>=0 ; i--){
        t = (t+(s[i] - '0')*pp)%p;
        ans += mp[t];
        mp[t]++;
        pp = pp*10%p;
    }
    cout<<ans;
}
