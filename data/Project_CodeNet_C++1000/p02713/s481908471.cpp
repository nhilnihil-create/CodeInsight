#include <bits/stdc++.h>
using namespace std;

int getgcd(int n, int m)
{
    int r;
    if (n > m) {
        int t = m;
        m = n;
        n = t;
    }
    while ((r = m % n) != 0) {
        m = n;
        n = r;
    }
    return n;
}
 
int main(){
    long long K;
    int gcd;
    long long sum=0;

    cin >> K;

    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++){
            for(int k=1;k<=K;k++){
                gcd = getgcd(getgcd(i,j),k);
                sum += gcd;
            }
        }
    }


    
 
    cout << sum << endl;
 
    return 0;
}