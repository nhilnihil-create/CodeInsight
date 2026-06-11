#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n, d;
    cin >> n >> d;
    int a[n][d];
    for(int i=0; i<n; ++i)
        for(int j=0; j<d; ++j)
            cin >> a[i][j];
        
    int ans=0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(i!=j){
                ll az=0;
                for(int k=0; k<d; ++k){
                    az += (a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
                }
                double dist = sqrt(az);

                if(floor(dist) == dist)
                    ans++;
            }
        }
    }
    cout << ans;
}
