#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)cnt++;
    }
    if(cnt<=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}