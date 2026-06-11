#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N , K , Mini = 0;
    cin >> N >> K;
    int F[N] ;
    for(int i =0 ; i < N ; ++i )
    {
        cin >> F[i] ;
    }
    sort( F , F + N ) ;
    for(int i = 0 ; i < K ; ++i)
    {
        Mini += F[i] ;

    }

    cout << Mini ;
    return 0;
}
