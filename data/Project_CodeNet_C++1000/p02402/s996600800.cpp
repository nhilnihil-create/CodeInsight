#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int x;
    cin>>x;
    vector<int>vec(x);
    for(int i=0;i<x;i++){
        cin>>vec[i];
    }
    int y = vec.at(0);
    for(int i=1;i<x;++i){
        y = min(y,vec.at(i));
    }
    int z = vec.at(0);
    for(int i=1;i<x;++i){
        z = max(z,vec.at(i));         
    }
    int w = vec.at(0);
    for(int i=1;i<x;++i){
        w = w+vec.at(i);
    }
    cout<<y<<" "<<z<<" "<<w<<endl;
    
}



