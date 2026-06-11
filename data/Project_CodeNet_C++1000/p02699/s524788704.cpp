#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i,a,b) for(int i=a,almo5t=b;i<almo5t;++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const int N = 0;
 
typedef long long int ll;
 
using namespace std;


 
int main(){
    FIN;
    //freopen("../input.txt", "r", stdin);freopen("../output.txt", "w", stdout);
    int s,w;cin>>s>>w;
    if(s>w){
        cout<<"safe";
    }else{
        cout<<"unsafe";
    }

    return 0;
}

// ============== Notes =============== //
// common bugs
// - remove reader 
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?, is MAXN correct?)
// - special cases (n=1, graph not connected?)
// - re-initialize efficiently between test cases