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
    ld W,H,x,y;
    cin >> W >> H >> x >> y;
    ld sq=W*H/2.;
    int count=0;
    if((x==W/2&&y==H/2)){
        count++;
    }
    cout << setprecision(9)<<sq <<" " <<count << endl;


}