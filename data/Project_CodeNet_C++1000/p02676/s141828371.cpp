#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
int main()
{
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    if(s.size()<=n)
    {
        cout << s ;

    }
    else if (s.size()!= n) {

        for(int i=0 ;i<n ;i++)
        {
            cout << s[i] ;
        }
        cout <<"..." ;
    }



    return 0 ;
}
