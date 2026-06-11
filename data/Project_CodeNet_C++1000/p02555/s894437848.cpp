#include <bits/stdc++.h>
//#include <atcoder/all>
using ll = long long;
using namespace std;
//using namespace atcoder;

int main() {
    int s;cin>>s;
    int a[s+1]{};
    a[0]=1;
    for (int i=3;i<=s;i++)
        a[i]=(a[i-1]+a[i-3])%1000000007;
    cout<<a[s]<<endl;
    return 0;
}