#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    string s;
    cin >> s;
    int n=s.size();
    vi a(n+1);
    int ten=1;
    for(int i=n-1;i>=0;i--){
        int kani=s[i]-'0';
        a[i]=kani*ten%2019;
        ten=ten*10%2019;
    }
    for(int i=n-1;i>0;i--){
        a[i-1]=(a[i-1]+a[i])%2019;
    }
    map<int,int> mp;
    for(int i=0;i<=n;i++){
        mp[a[i]]++;
    }
    int ans=0;
    for(auto x:mp){
        //cout << x.first << " " << x.second << endl;
        ans+=x.second*(x.second-1)/2;
    }
    cout << ans << endl;

}