#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

const ll MOD = 1e9+7;

int main(){
    string s;
    ll k;
    bool flag = false;
    cin >> s >> k;
    rep(i,0,s.size()){
        if(s[0] != s[i]) break;
        else if(i == s.size()-1){
            cout << (s.size()*k)/2 << endl;
            return 0;
        }
    }

    ll temp = 0,cnt = 0,memo = 0;
    rep(i,0,s.size()-1){
        if(s[i] != s[i+1]){
            if(!flag){
                flag = true;
                memo = temp+1;
            }
            cnt += (temp+1)/2;
            temp = 0;
        }
        else{
            temp++;
        }
    }

    if(s[0] == s[s.size()-1]){
        cout << (cnt - memo/2)*k + memo/2 + (temp+1)/2 + (memo + temp + 1)/2*(k-1) << endl;
    }
    else{
        cout << (cnt+(temp+1)/2)*k << endl;
    }


}
