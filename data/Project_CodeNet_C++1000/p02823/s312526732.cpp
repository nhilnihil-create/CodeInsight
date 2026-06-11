#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<lli, lli> pi;


int main()
{
    lli n, a, b;
    cin >> n >> a >> b;
    if((b-a) % 2 == 0){
        cout << (b-a)/2 << "\n";
    }
    else{
        cout << min({b-1, n-a, (a-1)+(b-(a-1))/2, (n-b+1)+(n-(a+(n-b)+1))/2}) << "\n";
    }

    return 0;
}
