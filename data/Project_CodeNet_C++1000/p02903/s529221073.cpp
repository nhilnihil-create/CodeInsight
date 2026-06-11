#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long h,w,a,b;
    cin>>h>>w>>a>>b;
    map<long long,pair<long long,bool>> tate,yoko;
    for(long long i=0;i<max(h,w);i++){
        tate[i]=make_pair(0,false);
        yoko[i]=make_pair(0,false);
    }
    
    vector<vector<long long>> grid(h,vector<long long>(w,0));
    
    for(long long i=0;i<h;i++){
        for(long long j=0;j<w;j++){
            if(j<a && i<b) cout<<0;
            if(j<a && i>=b) cout<<1;
            if(j>=a && i<b) cout<<1;
            if(j>=a && i>=b) cout<<0;
        }
        cout<<endl;
    }
    
    return 0;
}
