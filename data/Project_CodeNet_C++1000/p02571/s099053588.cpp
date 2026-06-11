#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;


int32_t main(){

    string a , b ;cin >> a >> b;
    int n = a.length() , m = b.length() , ans = 1e9;
    for(int i = 0 ; i < n - m + 1; ++i){
        string x = a.substr(i,m);
        // cout << x << endl;
        int c = 0;
        for(int j = 0 ; j < m ; ++j) if(x[j]!=b[j]) c++;
        ans = min(ans,c);
    }
    cout << ans << endl;
    return 0;
}