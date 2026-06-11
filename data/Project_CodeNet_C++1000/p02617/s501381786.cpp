#include <iostream>
long long n,a,b,ans;
using namespace std;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++)ans+=(i+1)*(n-i);
    //cout<<ans<<endl;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        ans-=a*(n-b+1);
    }
    cout<<ans<<endl;
}
