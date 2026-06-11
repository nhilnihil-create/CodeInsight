#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    double ans;
    if(n % 2 == 1) {
        ans = (double)(n/2 + 1)/n;
    }else{
        ans = (double)n/2/n;
    }
    printf("%.10f\n",ans);
}