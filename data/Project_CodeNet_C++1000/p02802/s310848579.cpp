#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<int,string> P;

#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

int main()
{
    int n,m;
    cin >> n >> m;
    vector<P> point(m);
    vector<bool> isAC(n,false);
    vector<int> countWA(n,0);
    rep(i,m)cin >> point[i].first >> point[i].second;
    ll count_ac=0;
    ll count_wa=0;
    rep(i,m){
        if(!isAC[point[i].first-1]){
            if(point[i].second=="AC"){
                count_ac++;
                count_wa+=countWA[point[i].first-1];
                isAC[point[i].first-1]=true;
            }else{
                countWA[point[i].first-1]++;
            }
        }
    }
    cout << count_ac << " " << count_wa << endl;
}