#include<bits/stdc++.h>
using namespace std;
#define int long long
 
#define check(a)         cout<<#a<<" : "<<a<<endl;
#define check2(a, b)     cout<<#a<<" : "<<a<<" | "<<#b<<" : "<<b<<endl;
#define check3(a, b, c)  cout<<#a<<" : "<<a<<" | "<<#b<<" : "<<b<<" | "<<#c<<" : "<<c<<endl;

void testCase(){
    int k; cin >> k;
    string add = "ACL";

    for(int i = 0; i < k; i++){
        cout << add;
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // int t; cin >> t;
    while(t--)
        testCase();
    
    return 0;
}