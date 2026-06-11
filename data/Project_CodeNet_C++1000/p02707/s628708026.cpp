#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    cin>>n;
    vector<int> a(n+1),boss(200010);
    repi(i,2,n+1){
        cin>>a[i];
        boss[a[i]]++;
    }
    repi(i,1,n+1){
        cout<<boss[i]<<endl;
    }
}