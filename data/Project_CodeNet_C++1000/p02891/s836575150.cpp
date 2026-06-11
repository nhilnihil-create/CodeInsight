#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int main() {
    string s ;
    ll k , i ;
    cin >> s >> k ;
    string t = s ;
    sort(t.begin(),t.end()) ;
    if (t[0]==t[t.size()-1]) {
        cout << (t.size()*k)/2 << endl ;
        return 0 ;
    }

    ll dif = 0 , dif1=0 ;
    for ( i = 1 ; i< s.size() ; i++) {
        if (s[i]==s[i-1]) {
            i++ , dif++ ;
        }
    }
    s= s+s ;
    if (k>1) {
        for ( i = 1 ; i< s.size() ; i++) {
        if (s[i]==s[i-1]) {
            i++ , dif1++ ;
        }
    }
    dif1-=dif ;
    }


    cout << dif+ (dif1 * (k-1) ) ;


}
