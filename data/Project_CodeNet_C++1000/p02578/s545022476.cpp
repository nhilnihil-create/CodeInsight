#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    long long n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int u=0;
    long long  ans=0;
    int biggest=0;
    while(u<n){
        biggest=max(a[u],biggest);
        int b1=biggest;
            ans+=b1-a[u];
        u++;
    }
    cout<<ans<<endl;
}

