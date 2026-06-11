#include <bits/stdc++.h>
#define Phuong_ ios_base::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a; i<=b; ++i)

/// easy access -------------
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<int,int> pi;
typedef tuple<bool, int, int> tp;
typedef vector<vector<int>> vv;
///-------------------------


int main()
{
    Phuong_; /// <3333
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    int ans=0;
    for(int i=0; i<n-2; ++i){
        for(int j=i+1; j<n-1; ++j){
            for(int k=j+1; k<n; ++k){
                if (a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k]){
                    if (a[i]+a[j]>a[k] && a[j]+a[k]>a[i] && a[i]+a[k] > a[j]) ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
