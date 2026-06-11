#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define int long long int
const int mod = 1000000007;
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

map<int,int>primes;

void factor(int n){
    map<int,int>m;
    for(int i=2; i*i<=n; i++){
        while(n%i == 0){
            m[i]++;
            n = n/i;
        }
    }
    if(n != 1){
        m[n] = 1;
    }
    for(auto x : m){
        primes[x.first]++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        factor(arr[i]);
    }
    string ans = "pairwise coprime";
    for(auto x : primes){
        if(x.second == n){
            ans = "not coprime";
            break;
        }
        if(x.second != 1){
            ans = "setwise coprime";
        }
    }
    cout<<ans<<endl;
    return 0;
}