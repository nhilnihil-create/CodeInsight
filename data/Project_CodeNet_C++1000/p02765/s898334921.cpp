#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int IINF = INT_MAX;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000000000
int main(){
    int n,r; cin >> n >> r;
    
    if(n < 10) cout << r + 100*(10 - n) << endl;
    else cout << r << endl;
    
    return 0;	
}