#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int k,n;
void test() {
    cin>>k>>n;
    vector<int> a(n),b(n);
    for (int i=0; i<n; ++i) {
        cin>>a[i];
        if (i) b[i]=a[i]-a[i-1];
    }
    b[0]=k-a[n-1]+a[0];
    cout<<k-*max_element(b.begin(),b.end())<<endl;
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