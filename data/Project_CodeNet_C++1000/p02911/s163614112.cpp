#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int a[n]={0};
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        a[x-1]++;
    }
    for(int i=0;i<n;i++){
        if(k-(q-a[i])>0)cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
    return 0;
}