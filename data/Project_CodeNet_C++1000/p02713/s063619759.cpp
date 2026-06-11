#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int gcd(int x,int y){
    return (x % y)? gcd(y, x % y) : y;
}
int main() {
    int n, a, sum; cin >> n;
    sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int o = 1; o <= n; o++){
                a = gcd(gcd(i , j) , o);

                sum = sum + a;
            }
        }
    }
    cout << sum << endl;
    

}