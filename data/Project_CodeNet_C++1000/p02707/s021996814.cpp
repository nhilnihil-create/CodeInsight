#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
int main() {
    int n;
    cin>>n;
    int stuff[n],boss[200010]={0};
    for(int i=2;i<=n;i++) cin>>stuff[i];
    for(int i=2;i<=n;i++) boss[stuff[i]]++;
    for(int i=1;i<=n;i++) cout<<boss[i]<<endl;
}