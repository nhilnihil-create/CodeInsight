#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<long long> a;
vector<long long> b;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i=0; i<n;i++) cin>>a[i]>>b[i];
    
    vector<int> id(n);
    iota(id.begin(), id.end(),0);
    sort(id.begin(), id.end(), [&](int i, int j){
        return b[i] < b[j];});
    long long sum=0;
    bool flag=true;
    for (auto i: id) {
        sum+=a[i];
        if (sum>b[i]) flag=false;
    }
    if (flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}
