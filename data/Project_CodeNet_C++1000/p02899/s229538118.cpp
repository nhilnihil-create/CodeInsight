#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> jun(n);
    rep(i,n){
        cin>>a[i];
        jun[a.at(i)-1]=i+1;
    }
    rep(i,n){
        cout<<jun[i]<<" ";
    }
    cout<<endl;
}