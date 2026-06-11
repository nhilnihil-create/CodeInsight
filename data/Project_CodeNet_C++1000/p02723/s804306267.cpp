#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string s;
void test() {
    cin>>s;
    cout<<((s[2]==s[3]&&s[4]==s[5])?"Yes":"No")<<endl;
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