#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=0;i<n;++i) cin>>a[i+1];

    for(int i=n;i>0;--i){
        int sum=0;
        for(int j=2;i*j<=n;++j) sum+=b[i*j];
        if(sum%2!=a[i]) b[i]=1;
    }

    int m=accumulate(b.begin(),b.end(),0);
    cout<<m<<endl;
    for(int i=0;i<n;++i){
        if(b[i+1]) cout<<i+1<<' ';
    }
    cout<<endl;
}