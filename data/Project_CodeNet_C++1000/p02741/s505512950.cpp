#include<bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
void test(T a){
    return ;
}

signed main(){
    int a[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k; cin >> k;
    cout << a[k-1] << endl;
}