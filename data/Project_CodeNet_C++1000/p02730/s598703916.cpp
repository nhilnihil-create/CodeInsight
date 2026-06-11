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
    rep(i,s.size()){
        if(s[i]!=s[s.size()-1-i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    rep(i,s.size()/2){
        if(s[i]!=s[s.size()/2-i-1]){
            cout<<"No"<<endl;
            return 0;
        }else if(s[i+s.size()/2+1]!=s[s.size()-1-i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}