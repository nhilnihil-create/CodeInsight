#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

class BinaryIndexedTree
{
private:
    typedef long long T;
    int n;
    vector<T> data;
public:
    // コンストラクタ
    BinaryIndexedTree(int n){
        this->n = n;
        data.assign(n+1, 0);
    }
    // k番目の要素にxを加算する
    void add(int k, T x){
        ++ k;
        while(k <= n){
            data[k] += x;
            k += k & -k;
        }
    }
    // 区間[0,k)の総和を返す
    T sum(int k){
        T ret = 0;
        while(k > 0){
            ret += data[k];
            k -= k & -k;
        }
        return ret;
    }
    // 区間[a,b)の総和を返す
    T sum(int a, int b){
        return sum(b) - sum(a);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    BinaryIndexedTree bit(n);
    for(int i=0; i<n; ++i){
        int a;
        cin >> a;
        bit.add(i, a);
    }

    for(int i=0; i<q; ++i){
        int t, x, y;
        cin >> t >> x >> y;

        if(t == 0)
            bit.add(x, y);
        else
            cout << bit.sum(x, y) << endl;
    }

    return 0;
}
