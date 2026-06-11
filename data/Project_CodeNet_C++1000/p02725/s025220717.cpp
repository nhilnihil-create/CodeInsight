#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>k>>n;
    int maxv=0,a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0){
            maxv=max(maxv,a[i]-a[i-1]);
        }
    }
    maxv=max(maxv,a[0]+k-a[n-1]);
    cout<<k-maxv<<endl;
    return 0;
}