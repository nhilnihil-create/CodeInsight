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
        sort(a.begin(),a.end());

        double ans=(double)(a[0]+a[1])/2;

        for(int i=2;i<n;i++){
            ans=(double)(ans+a[i])/2;

        }

        cout << ans << endl;
        return 0;
    }