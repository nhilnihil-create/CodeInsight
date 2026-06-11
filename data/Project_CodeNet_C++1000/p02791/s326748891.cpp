#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int a[n],minv=1e9;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        minv=min(minv,a[i]);
        if(minv==a[i])cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}