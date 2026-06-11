#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string  s ;
    cin >> s;
    vector <int> c(2019, 0) ; 
    int  ss=0,ans=0,cur=1;
    c[0] = 1 ; 
    for (int i=s.size()-1;i>=0;i--){
        ss = (ss+(s[i]-'0')*cur)%2019;
        ans += c[ss] ; 
        c[ss]++ ; 
        cur = (cur*10)%2019; 
    }
    cout << ans << endl ; 
    return 0;
}
