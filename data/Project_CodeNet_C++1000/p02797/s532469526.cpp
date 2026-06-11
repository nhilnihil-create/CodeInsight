#include<iostream>
using namespace std;

int main(){
    int n,k,s;
    cin>>n>>k>>s;
    for(int i=0;i<k;i++){
        cout<<s<<endl;
    }
    for(int i=0;i<n-k;i++){
        if(s==1e9) cout<<1<<endl;
        else cout<<1000000000<<endl;
    }
}