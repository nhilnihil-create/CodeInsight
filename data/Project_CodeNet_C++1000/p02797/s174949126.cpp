#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,k,s;
    cin>>n>>k>>s;
    vector<int>v(n,1);
    for(int i=0;i<n;i++) {
        if(i<k) v[i]=s;
        else {
            s==1e9?v[i]=s-1:v[i]+=s;
        }
    }
    for(int x:v) cout<<x<<" ";
}