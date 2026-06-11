#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    int h1, m1, h2, m2, k;
    cin>>h1>>m1>>h2>>m2>>k;
    int st, en;
    st=h1*60+m1;
    en=h2*60+m2;
    int ans=en-st-k;
    cout << ans << endl;
    return 0;
}
