#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,l;
    cin>>n>>l;
    int ans=0;
    int sum=n*(l+l+n-1)/2;
    int x;
    if(l>=0)x=l;
    else if(l+n-1<=0)x=l+n-1;
    else x=0;
    cout<<sum-x<<endl;
    return 0;
}