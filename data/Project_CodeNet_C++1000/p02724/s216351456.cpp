#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
int main() {
    int x,happy=0;
    cin>>x;
    happy+=(x/500)*1000+((x%500)/5)*5;
    cout<<happy<<endl;
}