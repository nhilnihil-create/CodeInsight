#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,l;
    cin>>n>>l;
    int sum=(l-1)*n+n*(n+1)/2;

    int a=1e9,b=0;
    for(int i=1;i<=n;i++){
        if(a>abs(l+i-1)){
            a=abs(l+i-1);
            b=i;
        }
    }
    cout<<sum-(l+b-1)<<endl;
}