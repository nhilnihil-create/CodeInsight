#include <bits/stdc++.h>
#define LL               long long
#define PB               push_back
using namespace std;


vector<int> readVec(int n) {
    vector<int> v;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        v.PB(x);
    }
    return v;
}
int main() {
    int n; cin>>n;
    vector <int> v=readVec(n);
    int c=0,mx,mn;
    for (int i=1;i<n-1;i++){
        mx=max(v[i-1],max(v[i],v[i+1]));
        mn=min(v[i-1],min(v[i],v[i+1]));
        if (v[i]!=mx &&v[i]!=mn) c++;
    }
    cout<<c<<'\n';
}