#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const ll mod = 1e9 + 7;
 
int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}
 
ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

bool is_prime(long long N){
    if (N == 1) return false;
    for (long long i = 2;i * i <= N;i++){
        if (N % i == 0) return false;
    }
    return true;
}
 
ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}
 
double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}
 
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
 
///////////////////////////////////////////////////////////////////////////////////

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> box(n+1);
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }

    for (int i = n;i >= 1;i--){
        int count = 0;
        for (int j = i * 2;j <= n;j += i){
            count += box[j];
        }
        if (a[i] != count % 2){
            box[i] = 1;
        }
    }

    vector<int> ans;
    for(int i = 1;i <= n;i++){
        if (box[i] == 1){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}