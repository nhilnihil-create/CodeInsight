#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool flag=true;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a%2>0)continue;
        else {
            if(a%3>0&&a%5>0)flag=false;
        }
    }
    if(flag)cout<<"APPROVED"<<endl;
    else cout<<"DENIED"<<endl;
    return 0;
}