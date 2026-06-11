#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int a,b;
    cin >> a >> b;
    if(a<10 && b<10)
        cout << a * b << endl;
    else
        cout << -1 << endl;
}