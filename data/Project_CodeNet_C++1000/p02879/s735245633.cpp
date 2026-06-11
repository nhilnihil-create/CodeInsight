#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;


int main(){
    int a,b;
    cin >> a >> b;
    if(a<10&&b<10)
        cout << a*b << endl;
    else
        cout << -1 << endl;
	return 0;   
}
