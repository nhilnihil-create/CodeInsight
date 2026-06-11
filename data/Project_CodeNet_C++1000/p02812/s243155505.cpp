#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    int n ;
    cin >> n ;
    cin.ignore() ;
    string str ;
    cin >> str ;
    int cnt = 0 ;
    for(int i = 0 ; i < str.length() && i < n ; i++)
    {
        if(i >= str.length()-2) break ;
        else
        {
            if(str[i] == 'A' && str[i+1] =='B' && str[i+2] == 'C') cnt++ ;
        }

    }
    cout << cnt << endl ;

}
