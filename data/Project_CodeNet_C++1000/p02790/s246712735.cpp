#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<double,int> P;

#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 11711711

int main()
{
    char a,b;
    cin >> a >> b;
    if(a<=b){
        rep(i,b-'0'){
            cout << a;
        }
        cout << endl;
    }else{
        rep(i,a-'0'){
            cout << b;
        }
        cout << endl;
    }
}