#include <bits/stdc++.h>
using namespace std;

uint64_t gcd_impl( uint64_t n, uint64_t m ) {
        for( int i = 0; i < 10; ++i ) {
                uint64_t t = n - m;
                bool q = m > t;
                n = q ? m : t;
                m = q ? t : m;
                if( m == 0 ) { return n; }
        }
        return gcd_impl( m, n % m );
}

uint64_t gcd( uint64_t n, uint64_t m ) {
        return n > m ? gcd_impl( n, m ) : gcd_impl( m, n );
}
uint64_t lcm(uint64_t a, uint64_t b){return a/gcd(a,b)*b;}

int main(void) {
    int64_t N;
    int64_t numerator;
    int64_t denominator;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    numerator = 1;
    for(int i=0;i<N;i++) {
        numerator = lcm(numerator,A[i]);
    }

    denominator = 0;
    for(int i=0;i<N;i++) {
        denominator += (numerator/A[i]);
    }

    cout << setprecision(12) << (double)numerator/(double)denominator << "\n";
    
    
    return 0;
}
