#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,L,i;
    cin >> N >> L;


    int ans = 0 ;

    for(i=1; i<=N; i++){
        ans += L+i-1;
    }

    if(L >= 0)
        ans -=  L ;
    else if( L <= -1 * N)
        ans -= (L + N - 1 );

    cout << ans << endl;

    return 0;
    
}