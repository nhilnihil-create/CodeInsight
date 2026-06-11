#include <bits/stdc++.h>
using namespace std;
typedef long long ll   ;  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    int k;
    cin >> k ;
    string p ;
    cin >> p ;
    int len=p.length() ;
    for (int i=0;i<len;i++){
        int y=p[i]-'A' ;
        y+=k;
        y=y%26;
        cout << s[y] ;
    }
    return 0;
}