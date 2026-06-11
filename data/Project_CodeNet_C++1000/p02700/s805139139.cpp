#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int A,B,C,D ;
    cin >>A >> B >> C >>D ;
    int winner = 0 ;
    while(1)
    {
        C -= B ;
        if(C<=0)
        {
            winner = 1 ;
            break ;
        }

        A-= D ;
        if(A<=0)
        {
            winner = 2 ;
            break ;
        }

    }
    if(winner==1)
    {
        cout << "Yes" << endl ;
    }
    else
    {
        cout << "No" << endl ;
    }
    
}