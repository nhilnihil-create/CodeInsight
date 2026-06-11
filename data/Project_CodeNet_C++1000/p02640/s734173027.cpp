#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y;cin>>x>>y;
    if(y%2!=0){
        cout <<"No"<<endl;
        return 0;
    }
    int mini=x*2;
    int maxi=x*4;
    if(y<=maxi && y>=mini){
        cout <<"Yes"<<endl;
    }else{
        cout <<"No"<<endl;
    }

}
