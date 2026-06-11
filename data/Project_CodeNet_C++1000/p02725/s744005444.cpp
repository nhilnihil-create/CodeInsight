#include <bits/stdc++.h>
using namespace std;
int main(void){
    int k,n;
    cin >> k >> n;
    
    vector<int> a(n);
    
    for (int i=0;i<n;i++){
        cin >>a.at(i);
    }
    
    int ans=k-a.at(n-1)+a.at(0);
    
    for(int i=0;i<n-1;i++){
        ans=max(ans,a.at((i+1))-a.at(i));
    }
    
    cout <<k-ans;
}
