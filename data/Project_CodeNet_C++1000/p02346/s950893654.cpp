#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class FenwickTree {
    int n;
    vector<T> data;
public:
    FenwickTree(int n):n(n), data(n, 0){}
    T sum(int i, int j){
        if(i)return sum(0, j) - sum(0, i - 1);
        T res = 0;
        for(; j>=0; j=(j&(j+1))-1)res += data[j];
        return res;
    }
    void add(int k, T v){
        for(; k<n; k|=k+1)data[k] += v;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    FenwickTree<int> ftree(n);
    while(q--){
        int com, x, y;
        cin >> com >> x >> y;
        if(com)cout << ftree.sum(x - 1, y - 1) << '\n'; else ftree.add(x - 1, y);
    }
    return 0;
}