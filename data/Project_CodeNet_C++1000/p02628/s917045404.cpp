#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    int p[1001];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p,p+n);
    int s=0;
    for(int i=0;i<k;i++){
        // cout<<p[i]<<" ";
        s=s+p[i];
    }
    cout<<s<<"\n";
}










