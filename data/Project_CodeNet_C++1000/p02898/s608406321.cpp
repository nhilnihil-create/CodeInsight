#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,cnt=0;
    cin>>n>>k;
    vector<int>h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
        if(h[i]>=k) cnt++;
    }
    cout<<cnt<<endl;
}