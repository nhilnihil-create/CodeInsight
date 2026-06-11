#include<iostream>
using namespace std;
bool eaten[101];
int main(){
    int n,k,d;
    int cnt=0;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>d;
        int a;
        for(int u=0;u<d;u++){
            cin>>a;
            eaten[a]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(eaten[i]==false){
            cnt++;
        }
       
    }
     cout<<cnt<<"\n";
    // for(int i=1;i<=n;i++){
        // cout<<i<<" "<<eaten[i]<<"\n";
    // }
}