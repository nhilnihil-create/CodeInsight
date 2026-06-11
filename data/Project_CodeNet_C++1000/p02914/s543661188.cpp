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
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<typename T>
vector<T> Gauss_Jordan(const vector<T> &v, const int &MAX){ //v[i]<2^MAX
    int n=v.size();
    vector<T> ret=v;
    int d=0;
    for(int k=MAX-1; k>=0; k--){
        int p=-1;
        for(int i=d; i<n; i++){
            if((ret[i]>>k)&1){
                p=i;
                break;
            }
        }
        if(p==-1) continue;
        swap(ret[d], ret[p]);
        for(int i=0; i<n; i++){
            if(i==d) continue;
            if((ret[i]>>k)&1) ret[i]^=ret[d];
        }
        d++;
    }
    return ret;
}
int main()
{
    int n;
    scanf("%d", &n);
    using ull=unsigned long long;
    const int MAX=60;
    ull s=0;
    vector<ull> a(n);
    for(int i=0; i<n; i++){
        scanf("%llu", &a[i]);
        s^=a[i];
    }
    for(int i=0; i<n; i++) a[i]&=(~s);
    vector<ull> b=Gauss_Jordan(a, MAX);
    ull t=0;
    for(int i=0; i<n; i++) t^=b[i];
    ull ans=s+(t<<1);
    printf("%llu\n", ans);
    return 0;
}