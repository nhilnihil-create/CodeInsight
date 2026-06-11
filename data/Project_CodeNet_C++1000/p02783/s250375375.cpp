#include<iostream>
using namespace std;
int main(){
    int h,a,ans=0;
    cin>>h>>a;
    while(h>0){
        h-=a;
        ans++;
    }
    cout<<ans;
}