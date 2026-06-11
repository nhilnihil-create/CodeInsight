#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    int k,n,ans=0;
    cin>>n>>k;
    vector<int>a(10000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    for(int i=n-1;i>n-k-1;i--){
        ans+=a[i];
    }
    cout<<ans<<endl;
}
