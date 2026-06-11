#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    int ans;
    if(n%(2*d+1)==0)ans=n/(2*d+1);
    else ans=n/(2*d+1)+1;
    cout<<ans<<endl;
    return 0;
}