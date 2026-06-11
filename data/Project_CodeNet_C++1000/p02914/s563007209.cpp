#include <bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<unsigned long> A(N);
    copy_n(istream_iterator<unsigned long>(cin), N, A.begin());
    vector<unsigned long> pw;
    unsigned long x{0}, o{0};
    for(const auto& i : A){
        x ^= i;
        o |= i;
    }
    for(unsigned long i = 60; i--; )if(((~x & o) >> i) & 1)pw.push_back(i);
    for(auto& i : A)i &= ~x;
    unsigned long a{0};
    for(const auto& i : pw){
        auto it = partition(A.begin(), A.end(), [&i](auto a){return ~(a >> i) & 1;});
        auto t = A.back();
        if((t >> i) & 1){
            A.pop_back();
            if(a < (a ^ t))a ^= t;
            if(A.empty())break;
            for(auto& j : A)if((j >> i) & 1)j ^= t;
        }
    }
    cout << x + (a * 2) << endl;
    return 0;
}