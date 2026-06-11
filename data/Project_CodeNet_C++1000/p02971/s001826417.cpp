#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    vector<int> id(n);
    iota(id.begin(), id.end(),0);
    sort(id.begin(), id.end(), [&](int i, int j){
        return a[i] > a[j];});   
    for (int i=0; i<n; i++){
        if (a[i]==a[id[0]]) cout<<a[id[1]]<<endl;
        else cout<<a[id[0]]<<endl;
    }
}
