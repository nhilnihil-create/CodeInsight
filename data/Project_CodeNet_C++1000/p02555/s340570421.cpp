#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

int main(){
    int s;
    cin >> s;

    vector<long long>a(s+1,0);
    a.at(0) = 1;
    for(int i=3; i<s+1; i++){
        a.at(i) = (a.at(i-1) + a.at(i-3))%mod;
    }
    cout << a.at(s)<<endl;
}