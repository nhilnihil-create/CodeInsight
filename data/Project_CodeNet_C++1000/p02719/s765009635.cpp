#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    long long n,k,ans;
    cin>>n>>k;
    ans=n%k;
    ans=min(ans,abs(ans-k));
    cout<<ans<<endl;
    return 0;
}