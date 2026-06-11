#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long int
const int mod = pow(10,9)+7;
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;


signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
         cin>>arr[i];
     }
    int res = 0;
    int bit[62] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<61; j++){
            if(1LL << j & arr[i]) bit[j]++;
        }
    }

    for(int i=0; i<61; i++){
        int sum = (bit[i] * (n - bit[i]))%mod;
        int val = (1LL << i)%mod;
        res += (sum * val)%mod;
        res = res%mod;
    }
    cout<<res%mod<<endl;

    return 0;
}