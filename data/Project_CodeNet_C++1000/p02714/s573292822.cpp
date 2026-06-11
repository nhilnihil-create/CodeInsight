
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
typedef long long ll;

using namespace std;
void fastio() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastio();
    int s;
    ll g=0;
    string a;
    cin>>s>>a;
    ll c[90]={0},k,l;
    for(int i=0; i<s; i++) {
        c[a[i]]++;
        for(int j=0; j<s; j++) {
            k=2*j+i;
            l=j+i;
            if(k>=s) break;
            if(a[i]!=a[l] && a[i]!=a[k] && a[l]!=a[k])
                g++;
        }
    }
    ll ans=c['R']*c['G']*c['B']-g;
    cout<<ans<<"\n";
    return 0;
}