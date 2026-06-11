#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> t(n),v(n);
    for(int i = 0; i<n;++i){
        cin>>t[i];
        v[i] = t[i];
    }
    sort(v.begin(),v.end());
    int diff = 0;
    for(int i = 0;i<n;++i){
        if(t[i] != v[i]){
            diff++;
        }
    }
    if(diff<=2){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    


    return 0;
}