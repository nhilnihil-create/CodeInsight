#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;
const int M=200010;
int n, m,r[M];
int root(int x){
    if (r[x] < 0) return x;
    return r[x] = root(r[x]);
}
bool Change(int x, int y) {
    x=root(x); y=root(y);
    if (x == y) return false;
    if (r[x] > r[y]) swap(x, y);
    r[x] += r[y]; r[y] = x;
    return true;
}
int size(int x){
	return -r[root(x)];
}
int main() {
    cin>>n>>m;
    memset(r,-1,sizeof r);
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--; b--;
        Change(a,b);
    }
    int ans=0;
    for(int i=0;i<n;i++)  ans=max(ans,size(i));
    cout<<ans<<endl;
    return 0;
}