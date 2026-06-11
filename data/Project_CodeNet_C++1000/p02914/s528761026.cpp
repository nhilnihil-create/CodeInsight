#include <bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<unsigned long> A(N);
    copy_n(istream_iterator<unsigned long>(cin), N, A.begin());
    unsigned long x{accumulate(A.begin(), A.end(), 0UL, bit_xor<>())};
    for(auto& i : A)i &= ~x;
    unsigned long a{0};
    for(unsigned long i = 1UL << 60; i; i >>= 1){
        if(partition(A.begin(), A.end(), [&i](auto a){return ~a & i;}) == A.end())continue;
        auto t = A.back();
        A.pop_back();
        if(a < (a ^ t))a ^= t;
        if(A.empty())break;
        for(auto& j : A)if(j & i)j ^= t;
    }
    cout << x + (a * 2) << endl;
    return 0;
}