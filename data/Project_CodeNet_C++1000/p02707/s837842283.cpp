#include <bits/stdc++.h>
using namespace std;
int main(){
    long a; cin >> a;
    vector<int> v(a);
    for(int i=0;i<a-1;i++){
        int b; cin >> b;
        v[b-1]++;
    }
    for(auto x:v)cout << x << endl;
}