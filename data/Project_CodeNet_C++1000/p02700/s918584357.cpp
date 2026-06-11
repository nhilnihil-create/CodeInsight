#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int takh,taks;
    int aokh,aoks;
    cin>>takh>>taks;
    cin>>aokh>>aoks;
    while(takh>0 || aokh>0){
        aokh-=taks;
        if(aokh<=0)
            break;
        takh-=aoks;
    }
    if(takh>0)
        cout<<"Yes";
    else
        cout<<"No";
}
