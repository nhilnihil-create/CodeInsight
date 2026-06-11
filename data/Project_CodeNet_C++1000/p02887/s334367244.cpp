#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define all(v) v.begin(),v.end()
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
    fast ;
    int n,c=0,i;
    string s ;
    cin >> n >> s ;
    for(i= 0 ; i < n-1 ; i++)
    {
        if(s[i]!=s[i+1])
            c++;
    }
    cout << c+1 << "\n";
    return 0;
}
