#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a,b,v,w,t;
    cin>>a>>v>>b>>w>>t;
    long long c=(v-w)*t,d=abs(a-b);
    if(c>=d)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
