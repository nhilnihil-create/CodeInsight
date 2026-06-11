//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

ll p(ll x){
    ll cnt=0;
    ll sum=0;
    while(x!=-1){
        sum+=cnt;
        cnt++;
        x--;
    }
    return sum;
}

int main(){
    string s; cin>>s;
    ll n=s.size();
    ll cnt1=0,cnt2=0,ans=0;
    ll j=0;
    while(s[j]=='>'){
        j++;
    }
    ans+=p(j);
    for(int i=j;i<n;i++){
        cnt1=0,cnt2=0;
        while(s[i]=='<'){
            cnt1++;
            i++;
        }
        while(s[i]=='>'){
            cnt2++;
            i++;
        }
        ans+=p(cnt1)+p(cnt2);
        ans-=min(cnt1,cnt2);
        i--;
        }
        cout<<ans<<endl;

    }















































