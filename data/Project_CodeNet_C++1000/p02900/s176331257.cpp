#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long GCD(long long x, long long y) {
    return y ? GCD(y, x%y) : x;
}
 
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){
    long long a,b;
    cin>>a>>b;
    auto pf=prime_factorize(GCD(a,b));
    cout<<pf.size()+1<<endl;
}