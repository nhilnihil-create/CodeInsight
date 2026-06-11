#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    string str;
    cin>>str;
    int n=str.size();
    reverse(str.begin(), str.end());
    int a[200000];
    int x=1;
    rep(i, n){
        a[i]=((str[i]-'0')*x)%2019;
        x=(x*10)%2019;
    }
    int s[200001];
    s[0]=0;
    rep(i, n){
        s[i+1]=(a[i]+s[i])%2019;
    }
    //rep(i, n+1) cout<<s[i]<<" ";
    //cout<<endl;
    map<int, int> cnt;
    rep(i, n+1){
        cnt[s[i]]++;
    }
    int ans=0;
    repit(it, cnt){
        int m=it->second;
        ans+=m*(m-1)/2;
    }
    cout << ans << endl;
    return 0;
}
