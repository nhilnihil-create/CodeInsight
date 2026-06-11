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


int main(){
    fast;
    string s;
    cin >> s;
    int l = s.length();
    if( s[l-1] == 's' ) s+="es";
    else s+= 's';
    cout << s << endl;
    return 0;
}