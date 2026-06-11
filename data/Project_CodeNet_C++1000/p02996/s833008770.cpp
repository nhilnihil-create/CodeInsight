#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<map<int,int>>mps(n);
    
    for(int i=0;i<n;i++){
        cin>>mps.at(i)[1]>>mps.at(i)[0];   
    }
    sort(mps.begin(),mps.end());
    int time=0;
    bool ok=true;
    for(int i=0;i<n;i++){
        mps.at(i)[0];
        time+=mps.at(i)[1];
        if(time<=mps.at(i)[0]) ok=true;
        else{
            ok=false;
            break;
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

    
      