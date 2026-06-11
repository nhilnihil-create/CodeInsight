#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
void test() {
    cin>>n;
    cout<<1000*(n/500)+(n%500)/5*5<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while (t--) {
    //     test();
    // }
    test();
    // for (int i=1; i<=t; ++i) {
    //     cout<<"Case #"<<i<<": ";
    //     test();
    // }
    return 0;
}