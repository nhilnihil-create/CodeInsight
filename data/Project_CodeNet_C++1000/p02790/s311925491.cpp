#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using p = pair<int,int>;
static const long long INF = 1000000007;

int main(){
    int a,b;
    cin >> a >> b;
    rep(i,max(a,b)){
        cout << min(a,b);
    }
    cout << endl;

}