
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;


const int mod=1000000007;
//const int mod=998244353;





int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t,n,m,k,q,x,a,b,c,d;
    cin>> n >> k;
    if(k>(n-1)*(n-2)/2)
        cout<<-1<<el;
    else{
        cout<<n-1+(n-1)*(n-2)/2-k<<el;
        for(int i=2; i<n+1; i++)
            cout <<1 <<' '<< i<<el;
        b=(n-1)*(n-2)/2-k;
        for(int i=2; i<n; i++){
            for(int j=i+1; j<=n; j++){
                if(b==0)
                    return 0;
                cout <<i <<' ' << j<<el;
                b--;
            }
        }
    }
    
    
    return 0;
}

