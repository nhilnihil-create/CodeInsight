#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

list<long> divisor(long n) {
    list<long> ret;
    for ( long i = 1; i * i <= n; i++ ) {
        if (n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    long N; cin >> N;
    long m = divisor(N - 1).size() - 1;
    list<long> L = divisor(N);
    L.pop_front();
    while(!(L.empty())) {
        long n = N, i = *(L.begin());
        while(n % i == 0) n /= i;
        if (n % i == 1) m++;
        L.pop_front();
    }
    cout << m << endl;
    return 0;
}