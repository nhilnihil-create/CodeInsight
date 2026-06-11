#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
#define Graph vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)
#define inf 1000000321
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};



int main(){
    ll L,R;
    cin >> L >> R;
    ll a,b;
    a = b = 2020;
    if(R-L > 3030){
        cout << 0 << endl;
        return 0;
    }
    else{
        for(ll i = L;i < R;i++){
            for(ll j=i+1;j<=R;j++){
                a = min(a,(i*j)%2019);
            }
        }
        cout << a << endl;
    }

}