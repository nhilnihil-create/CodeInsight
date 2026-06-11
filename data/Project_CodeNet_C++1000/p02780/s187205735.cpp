#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, k;
    cin >> n >> k;
    double ans = 0;
    vector<int> num(n+1);
    rep(i,n) cin >> num[i];
    int sum = 0;
    rep(i,k) sum += (num[i]+1);
    ans = sum;
    rep(i,n-k){
        sum -= (num[i]+1);
        sum += (num[i+k]+1);
        ans = max(ans, (double)sum);
    }
    ans /= 2.0;
    printf("%.10f",ans);
}