#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())
#define count(v,x) count(v.begin(),v.end(),x)
#define find(v,x) find(v.begin(),v.end(),x)


priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int n;
string s;

void solve(){
    cin >> n;
    cin >> s;
    int ans=0;
    for(char v1='0';v1<='9';v1++){
        for(char v2='0';v2<='9';v2++){
            for(char v3='0';v3<='9';v3++){
                string t;
                t+=v1;
                t+=v2;
                t+=v3;
                int p=0;
                for(int l=0;l<n;l++){
                    if(s[l]==t[p])p++;
                    if(p==3)break;
                }
                if(p==3)ans++;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}



