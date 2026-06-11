#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>k>>n;
    for(int i=n-k+1;i<=n+k-1;i++){
        if(n!=n+k-1)cout<<i<<" ";
        else cout<<i<<endl;
    }
    return 0;
}