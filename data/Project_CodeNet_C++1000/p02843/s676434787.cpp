#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>
#define vvec(s) vector<vector<s>>
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
#define YES(x) cout<<(x?"YES":"NO")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " " 
#define INF 10000000000
#define LINF 9000000000000000000
#define all(s) s.begin(),s.end()
void vout(vi v){
    for(lli i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli x,xc;
    cin >> x;
    xc = x;
    x %= 100;
    lli rec = 0;
    rec += (x / 5) * 105;
    x -= (x / 5) * 5;
    rec += (x / 4) * 104;
    x -= (x / 4) * 4;
    rec += (x / 3) * 103;
    x -= (x / 3) * 3;
    rec += (x / 2) * 102;
    x -= (x / 2) * 2;
    rec += (x / 1) * 101;
    x -= (x / 1) * 1;

    cout<<(rec > xc ?0:1)<<endl;
}