#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using ld  = long double;
template <class Itr> auto Median(Itr first, Itr last) {
    // when value_type is double or long double , you should use "round""
    // function these Iterator must be Random Access Iterator
    typename iterator_traits<Itr>::difference_type n = distance(first, last);
    sort(first, last);
    if (n % 2 == 1) {
        return *(first + n / 2);
    } else {
        return (*(first + n / 2) + *(first + n / 2 - 1)) / 2;
    }
}
int main(){
    Int N; cin >> N;
    vector<ld>A(N);
    vector<ld>B(N);
    for(int i = 0; i < N; ++i)
        cin >> A[i] >> B[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    auto Bmed = Median(B.begin(), B.end());
    auto Amed = Median(A.begin(), A.end());
    if(N % 2){
        cout << (Int)Bmed - (Int)Amed + 1 << endl;
    } else {
        cout << (Int)(2 * (Bmed - Amed) + 1) << endl;
    }
    
}
