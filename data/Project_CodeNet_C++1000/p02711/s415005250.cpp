#include <bits/stdc++.h>
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int n ;
    cin >> n ;
    int flag = 0 ;
    while(n)
    {
        if(n % 10 == 7)
        {
            flag = 1 ;
            break ;
        }
        n = n / 10 ;
    }
    if(flag) cout << "Yes\n" ;
    else cout <<"No\n" ;

}
