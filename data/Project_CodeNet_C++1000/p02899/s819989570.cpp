#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1],d[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[a[i]]=i;
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        if(i==n)cout<<d[i]<<endl;
        else cout<<d[i]<<" ";
    }
    return 0;
}