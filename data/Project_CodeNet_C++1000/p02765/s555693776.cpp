#include <bits/stdc++.h>
#define INF (1000000000000000000)
#define LL long long
//ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{

    int n = 0 ;
    int r = 0;

    cin >> n >> r;

    if(n < 10)
    {
        cout<<r+(100*(10-n));
    }else
    {
        cout<<r;
    }



}
