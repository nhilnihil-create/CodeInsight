#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 10101010

int main()
{
    int n;
    cin >> n;
    vector<int> l(n);

    rep(i,n)cin >> l[i];
    ssort(l);
    int count=0;
    rep(i,n-2){
        FOR(j,n-1,i+1){
            FOR(k,n,j+1){
                if(l[i]<l[j]+l[k]&&l[j]<l[i]+l[k]&&l[k]<l[i]+l[j]){
                    count++;
                }else{
                    break;
                }
            }
        }
    }
    cout << count << endl;
}