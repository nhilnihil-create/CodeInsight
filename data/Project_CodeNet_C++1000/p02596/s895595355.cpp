#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int>a(k);
    bool flag=true;
    for(int i=0;i<=k;i++){
        if(i==0)a[i]==7%k;
        a[i]=(10*a[i-1]+7)%k;
        if(a[i]==0){
            cout<<i+1<<endl;
            flag=false;
            break;
        }
    }
    if(flag)cout<<-1<<endl;
    return 0;
}