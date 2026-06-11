#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0){
        printf("%.10f\n", ((double)n / 2.0) / n);
    }else if(n % 2 != 0){
        printf("%.10f\n", (((double)n / 2) + 0.5) / n);
    }
    return 0;
}