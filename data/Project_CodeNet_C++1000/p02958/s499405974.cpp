#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;

    int p[n];
    rep(i,n)    cin >> p[i];

    int k(0);
    rep(i,n)    if(p[i]!=i+1)   k++;
    if(k<=2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}