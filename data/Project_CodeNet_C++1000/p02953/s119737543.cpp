#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    bool flag=true,change=true;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>0;i--){
        if(a[i]>=a[i-1])continue;
        else if(a[i]+1==a[i-1])a[i-1]--;
        else flag=false;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}