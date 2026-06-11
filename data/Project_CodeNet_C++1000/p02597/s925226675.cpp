#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=1e9,tw=0,tr=0;
    string s;
    cin>>n>>s;
    vector<int> w(n);
    vector<int> r(n);
    if(s[0]=='W') {tw++;w[0]++;} else {tr++;r[0]++;}
    for(int i=1;i<n;i++) {
        if(s[i]=='W') {
            tw++;w[i]++;
        }
        else {
            tr++;r[i]++;
        }
        w[i]+=w[i-1];
        r[i]+=r[i-1];
    }
    for(int i=0;i<n;i++) {
        int g = w[i],h=tr-r[i],j=min(g,h);
        ans=min(ans,g+h-j);
    }
    cout<<min(ans,min(tr,tw));
}