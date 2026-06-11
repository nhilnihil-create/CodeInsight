#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    ans+=n/500*1000;
    n%=500;
    ans+=n/5*5;
    cout<<ans<<endl;
    return 0;
}