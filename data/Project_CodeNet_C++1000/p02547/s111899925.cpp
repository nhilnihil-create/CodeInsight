#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a==b)
            cnt++;
        else
        {
            cnt=0;
        }
        
        if(cnt==3)
            return cout<<"Yes",0;
        
    }
    return cout<<"No",0;
}