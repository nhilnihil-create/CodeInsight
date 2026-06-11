#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define sz(x) int(x.size())
using ll = long long;
using P = pair<int,int>;
const ll LLINF = numeric_limits<long long>::max();
const int mod = 1000000007;
const int INF = 1001001001;

int main()
{
    string T;
    cin >> T;

    for(int i=0;i<T.length();i++){
        if(T[i] == '?'){
            T[i] = 'D'; 
        }
    }
    cout << T;
    return 0;
}