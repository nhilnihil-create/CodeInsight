#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
        a[i] = 1.0*(1+a[i])/2;
    }

    double ans=0;
    for(int i=0; i<k; ++i)
        ans+=a[i];
    

    double csum=ans;
    for(int i=k; i<n; ++i){
        csum -= a[i-k];
        csum += a[i];

        ans = max(ans, csum);
    }

    cout << fixed << setprecision(10) <<ans;
}
