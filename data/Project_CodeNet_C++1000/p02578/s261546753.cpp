#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,ans=0;
    cin>>n;
    vector<long long int>a(10000000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            ans+=((a[i])-a[i+1]);
            a[i+1]=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
