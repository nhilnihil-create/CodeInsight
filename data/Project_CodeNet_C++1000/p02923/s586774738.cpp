#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
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
#define MAX 100000

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n){
        cin >> h[i];
    }
    int max_=0;
    int tmp=0;
    rep(i,n-1){
        if(h[i]>=h[i+1]){
            tmp++;
        }else{
            max_=max(max_,tmp);
            tmp=0;
        }
    }
    max_=max(max_,tmp);
    cout << max_ << endl;
}