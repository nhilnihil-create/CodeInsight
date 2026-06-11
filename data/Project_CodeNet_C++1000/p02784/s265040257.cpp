#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int h,n;
    cin>>h>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum>=h)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}