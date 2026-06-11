#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    int n, m;
    cin>>n>>m;
    int suma=0;
    rep(i, m){
        int a;
        cin>>a;
        suma+=a;
    }

    int ans= (n-suma>=0)?(n-suma):(-1);
    cout << ans << endl;
    return 0;
}
