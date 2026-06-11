#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set =
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod=1e9+7;
int memo[1000010][13];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a;
    cin>>a;
    memo[0][0]=1;
    for(int i=0;i<a.length();i++){
        for(int c=0;c<=9;c++){
            int r=a[i]-'0';
            if(a[i]=='?')
                r=c;
            for(int d=0;d<=12;d++){
                memo[i+1][((10*d)+r)%13]+=memo[i][d]%mod;
                memo[i+1][((10*d)+r)%13]%=mod;
            }
            if(a[i]!='?')
                break;
        }
    }
    cout<<memo[a.length()][5]%mod;
}