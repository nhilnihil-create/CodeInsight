#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
 

// HOW TO DO 
// 1. input 
//    int N 
//    vector P,Q
// 2. 入力されたそれぞれの順列が何番目にあるか返す =  next-permutation(first, last)
//    first = 1つ目の順列
//    last = 入力された順列
// 3.  output |a-b|

// 入力された順列が何番目にあるか返す
// next_permutation (first、last)
// first = 1つ目の順列, last = 入力された順列
int solve(vector<int> v, vector<int> P)
{
    int ret = 0;
    while (v != P)
    {
        next_permutation(ALL(v));
        ret++;
    }
    return ret;
}

int main()
{
    // input 
    int N;  
    cin >> N;  
    vector<int> P(N), Q(N);
    cin >> P >> Q;

    // 順列の1つ目　
    // Ex) 大きさ3の順列：v = (1,2,3)
    vector<int> v(N);
    REP(i, N) v[i] = i + 1;

    // 入力された順列が何番目にあるか返す
    // next_permutation (first、last)
    // first = 1つ目の順列
    // last = 入力された順列
    cout << abs(solve(v, P) - solve(v, Q)) << endl;
}
