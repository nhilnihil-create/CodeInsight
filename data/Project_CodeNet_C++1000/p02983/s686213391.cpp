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
using Graf=vector<vector<int>>;
#define MAX 100000

int main()
{
    ll l,r;
    cin >> l >> r;
    int mod_l=l%2019;
    int mod_r=r%2019;
    if(mod_r<=mod_l){
        cout << 0 << endl;
    }else{
        if(l+2019<r){
            cout << 0 << endl;
        }else{
            int min=MAX;
            for(int i=mod_l;i<mod_r;++i){
                for(int j=i+1;j<=mod_r;++j){
                    if((i*j)%2019<min){
                        min=(i*j)%2019;
                    }
                }
            }
            cout << min << endl;
        }
    }
}