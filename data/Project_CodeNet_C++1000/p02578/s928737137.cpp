#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[200010];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum=0;
    for(int i=1;i<n;i++){
        int sa=a[i-1]-a[i];
        if(sa>0){
            sum+=sa;
            a[i]+=sa;
        }
    }
    cout<<sum<<"\n";
    return(0);
}