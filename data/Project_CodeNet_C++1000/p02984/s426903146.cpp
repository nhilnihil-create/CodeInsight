#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n),x(n);
    for(int i=0;i<n;++i) cin>>a[i];
    long long sum=0;
    for(int i=0;i<n;++i) sum+=a[i];
    //cout<<"sum: "<<sum<<endl;
    x[0]=sum;
    for(int i=1;i<n;i+=2){
        x[0]-=2*a[i];
    }
    //cout<<"x0: "<<x[0]<<endl;
    for(int i=0;i<n-1;++i){
        x[i+1]=2*a[i]-x[i];
    }

    for(int i=0;i<n;++i) cout<<x[i]<<' ';
    cout<<endl;
}
