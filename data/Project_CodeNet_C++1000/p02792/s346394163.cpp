#include<bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T>
using V = vector<T>;
template<class T>
using VV = V<V<T> >;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for(int i=m; i<n; i++)

int head(int n){
    if(n / 10 == 0) return n;
    else return head(n / 10);
}

int tail(int n){
    return n % 10;
}

int main(){
    int N;
    cin  >> N;
    
    VV<int> c(10, V<int>(10, 0));
    rep2(i, 1, N+1) c.at(head(i)).at(tail(i))++;
    
    ll sum = 0;
    rep(i, 10){
        rep(j, 10)  sum += (ll)c.at(i).at(j) * c.at(j).at(i);
    }

    cout << sum << endl;
}