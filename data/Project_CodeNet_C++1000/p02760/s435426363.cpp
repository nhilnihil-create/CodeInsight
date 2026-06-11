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
using Graf=vector<vector<int>>;
#define MAX 10000007

int main()
{
    Graf a(3,vector<int>(3));
    
    rep(i,3){
        rep(j,3){
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n)cin >> b[i];

    rep(k,n){
        rep(i,3){
            rep(j,3){
                if(a[i][j]==b[k]){
                    a[i][j]=MAX;
                }
            }
        }
    }
    bool ans=false;

    rep(i,3){
        int num=0;
        rep(j,3){
            if(a[i][j]==MAX){
                num++;
            }
        }
        if(num==3){
            ans=true;
            Yes;return 0;
        }
        num=0;
    }
    rep(i,3){
        int num=0;
        rep(j,3){
            if(a[j][i]==MAX){
                num++;
            }
        }
        if(num==3){
            Yes;return 0;
        }
    }
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]==MAX){
        Yes;return 0;
    }
    if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[0][2]==MAX){
        Yes;return 0;
    }
    No;
}