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
    vector<long long int>a(1000000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    for(int i=0;i<n-1;i++){
        ans+=a[(i+1)/2];
    }
    cout<<ans<<endl;

    return 0;
}
