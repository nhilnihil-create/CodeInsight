#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(){
    long long n, m;

    cin >> n >> m;

    multiset<long long> s;

    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        s.insert(a);
    }

    multiset<long long>::iterator it;
    for(long long i = 0; i < m; i++){
        it = s.end();
        it--;
        long long maxv = *it;
        s.erase(it);
        maxv = maxv/2;
        s.insert(maxv);
    }

    

    long long sum = 0;
    multiset<long long>::iterator it2;
    for(it2 = s.begin(); it2 != s.end(); it2++){
        sum += *it2;
    }

    cout << sum << endl;

    return 0;
}