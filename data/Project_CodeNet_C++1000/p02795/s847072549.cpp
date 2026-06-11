#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h,w,n,ans=0;
    cin>>h>>w>>n;
    int a = 0;
    for(int i=0; i<min(h,w); i++) {
        a += max(h,w);
        ans++;
        if(a >= n) break;
    }
    cout<<ans<<endl;
}