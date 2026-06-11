#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    long long int n,d,ans=0;
    cin>>n>>d;
    vector<pair<long long int,long long int>>a(1000000);
    for(long long int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        if(a[i].first*a[i].first+a[i].second*a[i].second<=d*d){
            ans++;
        }
    }
    cout<<ans<<endl;

}
