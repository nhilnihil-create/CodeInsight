#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, c; vector<int> a, b;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    for(int i = 0; i < n; i++) if(s[i] == 'o') {a.push_back(i); i+=c;};
    for(int i = n-1; i >= 0; i--) if(s[i] == 'o') {b.push_back(i); i-=c;};
    for(int i = 0; i < k; i++) if(a[i] == b[k-i-1]) {cout<<a[i] + 1<<'\n';};
    return 0;
}