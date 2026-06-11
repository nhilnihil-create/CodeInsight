#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long double ans=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        ans+=1.00000/a[i];
    }
    ans=1.00000/ans;
    cout<<ans<<endl;
}