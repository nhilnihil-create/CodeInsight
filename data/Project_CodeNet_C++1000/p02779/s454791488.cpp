#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int n ;
    cin >> n ;
    set <int> x ;
    int temp ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp ;
        x.insert(temp) ;
    }
    if(x.size() == n) cout <<"YES\n" ;
    else cout <<"NO\n" ;

}
