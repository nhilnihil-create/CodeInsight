#include<bits/stdc++.h>
using namespace std;
using Long = long long;

#define forn(i,n) for( int i = 0 ; i < n ; ++i )
#define pb push_back
#define pf push_front
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define forll(it, cnt) for( auto &it : cnt )
#define endl '\n'
#define debug(x) cout << "[" << #x <<" = " << " ]" << endl
#define ff first
#define ss second
#define fast ios::sync_with_stdio(false); cin.tie(NULL)

int a[2][105];

int main(){
    fast;
    int n;
    cin >> n;
    for( int i = 0 ; i < n; ++ i){
        for( int j = 0 ; j < 2 ; ++j ){
            cin >> a[j][i];
        }
    }
    for( int i = 0 ; i <= n - 3 ; ++i ){
        int tot = 0;
        for( int j = i ; j <= i + 2 ; ++j ){
            if( a[0][j] == a[1][j] ) tot++;
        }
        if( tot == 3 ) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}