#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,i,j;
    double ans = 0;
    cin >> N;
    int X[N],Y[N];
    for(i = 0;i < N;i++){
        cin >> X[i] >> Y[i];
    }
    for(i = 0;i < N - 1;i++){
        for(j = i + 1;j < N;j++){
            ans += sqrtl(abs(X[i] - X[j]) * abs(X[i] - X[j]) + abs(Y[i] - Y[j]) * abs(Y[i] - Y[j]));
        }
    }
    ans *= N - 1;
    ans /= (N * (N - 1) / 2);
    printf("%lf\n",ans);
}