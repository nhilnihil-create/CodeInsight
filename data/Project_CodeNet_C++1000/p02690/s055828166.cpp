#include <bits/stdc++.h>

using namespace std;
long long a[10001];
long long x;
int main(){
    cin >> x;
    long long n = pow(1e11,1.0/5);
    for (long long i = 1; i <= n; i++) a[i] = i*i*i*i*i;
    for (long long i = n + 1; i <= 2*n; i++){
        long long temp = i - n;
        a[i] = - (temp*temp*temp*temp*temp);
    }
    long long p , q;
    for (int i = 0; i <= 2*n; i++)
        for (int j = 0; j <= 2*n; j++)
            if (a[i] - a[j] == x){
                p = ((i <= n) ? i : -(i - n)) , q = ((j <= n) ? j : -(j - n));
                //cout << p << " " << q << "\n";
            }
    cout << p << " " << q;
    return 0;
}