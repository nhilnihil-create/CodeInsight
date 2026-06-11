#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    double sum = 0;
    rep(i, N){
        double a;
        cin >> a;
        sum += 1/a;
    }
    printf("%.6f\n", 1/sum);
    return 0;
}