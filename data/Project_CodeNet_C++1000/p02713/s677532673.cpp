#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll sum = 0;
    int N; cin >> N;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int l=1;l<=N;l++){
                sum += gcd(gcd(i, j),l);
            }
        }
    }
    cout << sum << endl;
}