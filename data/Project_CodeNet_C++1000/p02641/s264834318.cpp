#include<iostream>
#include<algorithm>
#include<cmath>
//#include<string>
//#include<set>
//#include<vector>
//#include<iomanip>
using namespace std;
int ind=0;
int down(int x,int d, int arr[],int len);
int up(int x,int d,int arr[],int len){
    for(int i=ind;i<len;i++){
        if(x+d<arr[i]){return x+d;}
        if(x+d==arr[i]){return down(x,d+1,arr,len);}
    }
    return x+d;
}
int down(int x,int d, int arr[],int len){
    for(int i=ind-1;i>=0;i--){
        if(x-d>arr[i]){return x-d;}
        if(x-d==arr[i]){return up(x,d,arr,len);}
    }
    return x-d;
}
int main(){

    int x,n,q=0;
    cin>>x>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<x){ind++;}
        else if(arr[i]==x){q=1;}
    }
    sort(arr,arr+n);
    if(q==1){cout<<up(x,0,arr,n);}
    else if(q==0){cout<<x;}
    return 0;
}
