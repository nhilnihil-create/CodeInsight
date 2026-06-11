#include <iostream>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int a[3];
    repi(i,3,0){
        cin >> a[i];
    }
    int index[3] = {0,1,2};
    int ans = INF;
    do{
        int tmp = a[index[0]] + a[index[1]];
        ans = min(ans,tmp);
    }while(next_permutation(index,index + 3));
    cout << ans << endl;
    return 0;
}