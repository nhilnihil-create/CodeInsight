#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string  s ;
    cin >> s;
    reverse(s.begin(),s.end()) ; 
    map <int,int> c;
    int  ss=0,ans=0,cur=1;
    c[0] = 1 ; 
    for (int i=0;i<s.size();i++){
        ss = (ss+((s[i]-'0')*cur))%2019;
        ans += c[ss] ; 
        c[ss]++ ; 
        cur = (cur*10)%2019; 
    }
    cout << ans << endl ; 
    return 0;
}
