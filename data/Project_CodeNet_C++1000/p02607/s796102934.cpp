//
//  main.cpp
//  AISING2020B

#include <iostream>
using namespace std;
using ll = long long;int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int a[110]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int j=1;j<=n;j+=2){
        if(a[j]%2==1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
