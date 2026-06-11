#include <bits/stdc++.h>
using namespace std;
long f(long x){
    return x*(x-1)/2;
}
int main(void){
    long a,n; cin >> a;
    vector<int> v(200001);
    vector<int> w(a);
    for(int i=0;i<a;i++){
        cin >> n; v[n]++;
        w[i] = n;
    }
    long sum = 0;
    for(auto x:v)sum += f(x);
    for(auto y:w)cout << sum - f(v[y]) + f(v[y]-1) << endl;
}