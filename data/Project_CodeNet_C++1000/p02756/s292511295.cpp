// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b=0,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    char c;
    cin>>str;
    deque<char> ch;
    rep(i,str.length()) {
        ch.push_back(str[i]);
    }
    cin >>n;
    rep(i,n){
        cin>>d;
        if(d==1){
           b++;
           b%=2;
        }else{
            cin>>a>>c;
            if(a==1){
                if(b==1) ch.push_back(c);
                else ch.push_front(c);
            }else{
                if(b==1) ch.push_front(c);
                else ch.push_back(c);
            }
        }
        
    }
    if(b==1) {
        while(!ch.empty()){
            cout<<ch.back();
            ch.pop_back();
        }
        }else{
            while(!ch.empty()){
            cout<<ch.front();
            ch.pop_front();
        
        }
    }

    return 0;
}
