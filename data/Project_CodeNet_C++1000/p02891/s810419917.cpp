//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    string s; cin>>s;
    ll k; cin>>k;
    ll ans=0,cnt=0;
    if(s[0]!=s[s.size()-1]){
        rep(i,s.size()){
            cnt=0;
            while(s[i]==s[i+1]){
                i++;
                cnt++;
            }
            ans+=(cnt+1)/2;
        }
        cout<<ans*k<<endl;
        return 0;
    }
    if(s.size()==1){
        cout<<k/2<<endl;
        return 0;
    }
    ll l=0,r=0;
    cnt=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
            if(i==s.size()-2){
                l=cnt+1;
                break;
            }
            continue;
        }
        l=cnt+1;
        break;
    }
    cnt=0;
    for(int i=s.size()-1;0<=i;i--){
        if(s[i]==s[i-1]){
            cnt++;
            continue;
        }
        r =cnt+1;
        break;
    }
    //cout<<l<<endl;
    //cout<<r<<endl;
    if(l+r>=s.size()){
        cout<<s.size()*k/2<<endl;
        return 0;
    }
    for(int i=l;i<s.size()-r;i++){
        cnt=0;
        while(s[i]==s[i+1]){
            i++;
            cnt++;
        }
        ans+=(cnt+1)/2;
    }

ll A=(r+l)/2*(k-1)+l/2+r/2+ans*k;
cout<<A<<endl;
}
















































