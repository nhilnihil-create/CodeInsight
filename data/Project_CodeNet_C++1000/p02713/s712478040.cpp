#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a%b==0){
        return b;
    }
    return gcd(b, a%b);
}
int main() {
    int N;
    cin >> N;
    int ans=0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            for (int l=1; l<=N; l++){
                int x=gcd(i,gcd(j,l));
                ans+=x;
            }
        }
    }
    cout << ans << endl;
}