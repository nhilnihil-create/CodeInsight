#include <bits/stdc++.h>
using namespace std;

    int my_gcd(int x,int y) {
        if (x%y==0) {
            return y;
        }
        return my_gcd(y,x%y);
    }

int main(void){
    long double K;
    cin >> K;
    

    int64_t sum=0;
    
    for (int i=1;i<K+1;i++) {
        for (int j=1;j<K+1;j++) {
            int gcd1=my_gcd(i,j);
            for (int k=1;k<K+1;k++) {
                int gcd2=my_gcd(gcd1,k);
                sum+=gcd2;
            }
        }
    }
    cout << sum << endl;
    
}


