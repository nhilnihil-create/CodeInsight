#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double n, s[1001], sum, ans;
    while(cin >> n){
        if(n==0) break;
        sum=0;
        ans=0;
        for(int i=0; i<n; i++){
            cin >> s[i];
            sum += s[i];
        }
        sum /= n;
        for(int i=0; i<n; i++){
            ans += (s[i] - sum)*(s[i] - sum);
        }
        ans /= n;
        ans = sqrt(ans);
        printf("%f\n", ans);
    }
    return 0;
}