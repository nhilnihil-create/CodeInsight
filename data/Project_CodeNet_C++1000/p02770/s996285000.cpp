#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    int k, q; cin>>k>>q;
    ll d[5050];
    for(int i=0; i<k; i++) cin>>d[i];
    while(q--){
        ll n, x, m;
        cin>>n>>x>>m;
        ll e[5050];
        x%=m;
        ll s=0, t=0;
        ll cnt=0, cnt1=0;
        for(int i=0; i<k; i++){
            e[i]=d[i]%m;
            if(e[i]==0) cnt++;
            if(e[i]==0 && i<(n-1)%k) cnt1++;
            s+=e[i];
            if(i<(n-1)%k) t+=e[i];
        }
        x+=s*((n-1)/k)+t;
        x/=m;
        cout<<n-1-x-cnt*((n-1)/k)-cnt1<<endl;
    }
    return 0;
}
