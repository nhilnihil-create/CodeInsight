#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    int n ;
    cin >> n ;
    vector<int> a (n) ;
    vector<int> b (1000005) ;
    rep(i, n){
        cin >> a[i] ;
        b[a[i]] += 1 ;
    }
    sort(a.begin(),a.end()) ;
    int mx = a[n - 1] ;
    vector<int> nums (mx + 1) ;
    rep(i, n){
        int f = a[i] ;
        for(int j = 2*f; j <= mx; j += f){
            if(nums[j] == 0){
                nums[j] += 1 ;
            }
        }
    }
    int ans = 0 ;
    rep(i, n){
        if(nums[a[i]] == 0 && b[a[i]] == 1){
            ans++ ;
        }
    }
    cout << ans << endl ;
}