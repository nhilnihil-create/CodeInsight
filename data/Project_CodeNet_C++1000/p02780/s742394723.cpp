#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 2e+5;
double E[MAX], sumE[MAX];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        E[i] = (p+1) / (double)2;
    }
    sumE[0] = 0;
    for(int i = 1; i <= n; i++){
       sumE[i] = sumE[i-1] + E[i-1];
    }
    double ans = 0;
    for(int i = 0; i <= n-k; i++){
        ans = max(ans, sumE[i+k] - sumE[i]);
    }
    printf("%.7f\n", ans);
    return 0;
}