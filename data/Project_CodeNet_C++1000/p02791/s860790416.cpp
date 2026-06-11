#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
        int n;
        cin >> n;
        vector<int> a(n);

        rep(i,n){
            cin >> a[i];
        }
        int ma=a[0];
        int mi=inf;
        int ans = 1;
        rep(i,n){
            if(mi>=a[i] && i!=0){
                ans++;
               // cout << a[i] << endl;
            }
    mi=min(mi,a[i]);
        }   
        cout << ans << endl;

    }