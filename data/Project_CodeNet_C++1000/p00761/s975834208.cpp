#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int vtoi(vector<int> v){
    int n=0;
    for(int i=0;i<v.size();++i){
        n += v[i] * pow(10, i);
    }
    return n;
}

vector<int> itov(int n, int L){
    vector<int> v;
    for(int i=0;i<L;++i){
        v.push_back(n%10);
        n = n / 10;
    }
    return v;
}

int main(){
    while(true){
        vector<int> a;
        int L;
        int n;
        int i=0, j=0;
        int x, y;
        cin >> n >> L;
        if(!(n||L)) break;
        a.push_back(n);
        for(i=0;;++i){
            vector<int> v = itov(a.back(), L);
            sort(v.begin(), v.end(), greater<int>());
            x = vtoi(v);
            sort(v.begin(), v.end());
            y = vtoi(v);
            for(j=0;j<i;++j){
                if(a[j] == y-x) break;
            }
            if(a[j] == y-x) break;
            a.push_back(y-x);
        }
        cout << j << ' ';
        cout << y-x << ' ';
        cout << i-j+1 << endl;
    }
}