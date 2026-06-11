//https://atcoder.jp/contests/abc171/tasks/abc171_d
#include<iostream>
using namespace std;
int main(){
    long long int a[100001]={0};
    long long int sum=0,temp=0,n,q;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        a[temp]++;
        sum+=temp;
    }
    cin>>q;
    long long int ans[q]={0};
    for(int i=0;i<q;i++){
        long long int b,c;
        cin>>b>>c;
        sum=sum + a[b]*(c-b);
        a[c]+=a[b];
        a[b]=0;
        ans[i]=sum;
    }
    for(auto s:ans){
        cout<<s<<"\n";
    }
    return 0;
}