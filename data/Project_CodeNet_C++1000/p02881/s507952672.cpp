#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long ans=1e18;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            ans=min(ans,(i-1)+(n/i-1));
        }
    }
    cout<<ans<<endl;
}