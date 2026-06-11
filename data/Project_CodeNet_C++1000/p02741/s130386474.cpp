#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;

typedef long double ld;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll arr[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    
    ll k;
    cin>>k;
    k--;
    cout<<arr[k]<<endl;
    
}
