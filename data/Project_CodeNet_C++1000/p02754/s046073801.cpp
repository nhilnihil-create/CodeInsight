#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    long long n,a,b;
    cin>>n>>a>>b;
    long long ans=(n/(a+b))*a+min(n%(a+b),a);
    cout<<ans<<endl;
    return 0;
}