#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

using Graf_char=vector<vector<char>>;
using Graf_int=vector<vector<int>>;
#define MAX 10000000

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    map<string,ll> count;
    rep(i,n)cin >> s[i];
    stack<string> st;
    rep(i,n){
        ssort(s[i]);
        if(count[s[i]]==0){
            st.push(s[i]);
        }
        count[s[i]]++;
    }
    ll ans=0;
    while(!st.empty()){
        ll num=count[st.top()];
        if(num>1){
            ans+=num*(num-1);
        }
        st.pop();
    }
    cout << ans/2 << endl;
    
}