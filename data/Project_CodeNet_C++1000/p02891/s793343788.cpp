#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s;cin>>s;
    map<char,int> mp;
    ll k;cin>>k;
    ll buf1=0,buf2=0;
    bool b=false;
    mp[s[0]]++;
    rep(i,s.size()-1){
        mp[s[i+1]]++;
        if(s[i]==s[i+1]){
            if(b)b=false;
            else{
                b=true;
                buf1++;
            }
        }else b=false;
    }
    if(mp.size()==1){
        cout<<(s.size()*k)/2<<endl;
      	return 0;
    }
    if(s[0]!=s[s.size()-1]){
        cout<<buf1*k<<endl;
        return 0;
    }
    ll A=1,B=1;
    rep(i,s.size()-1){
        if(s[i]!=s[i+1])break;
        else A++;
    }
    reverse(s.begin(),s.end());
    rep(i,s.size()-1){
        if(s[i]!=s[i+1])break;
        else B++;
    }
    buf2=A/2+B/2-(A+B)/2;
    ll res=buf1*k-buf2*(k-1);
    cout<<res<<endl;
}