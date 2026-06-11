#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n),b(n);
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n%2){
        long long r=b[n/2];
        long long l=a[n/2];
        cout<<r-l+1<<endl;
    }
    else{
        long long r=b[n/2-1]+b[n/2];
        long long l=a[n/2-1]+a[n/2];
        cout<<r-l+1<<endl;
    }
}