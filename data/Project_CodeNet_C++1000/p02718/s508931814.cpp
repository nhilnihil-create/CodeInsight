#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n],sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]*4*m>=sum)cnt++;
    }
    if(cnt>=m)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}