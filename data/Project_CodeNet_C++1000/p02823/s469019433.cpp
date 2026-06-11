
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#include<string>
using namespace std;
#define ll long long
typedef pair<ll , ll > pii;
ll mod=998244353;
ll p=1e9+7;

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    ll n,a,b;
    cin>>n>>a>>b;
    if( (b-a) %2 == 0 ){
        cout<<(b-a)/2;
    }
    else{
        ll ans=min(a-1,n-b)+1+(b-a-1)/2;
        cout<<ans;
    }
    return 0;
}
