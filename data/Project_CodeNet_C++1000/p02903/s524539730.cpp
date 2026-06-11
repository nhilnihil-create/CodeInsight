#include <bits/stdc++.h>
#define rep(i, a) for (ll i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

int s[1001][1001];

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    rep(i,h){
        rep(j,w){
            if(j < a){
                if(i < h-b) cout << 1;
                else cout << 0;
            }else{
                if(i < h-b) cout << 0;
                else cout << 1;
            }
        }
        cout << endl;
    }
}