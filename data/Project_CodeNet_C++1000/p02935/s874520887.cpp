#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    vector<int >v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    float gini = v[0];
    for(int i=1;i<n;i++){
        gini = (gini+v[i])/2;
    }
    cout<<gini;
}