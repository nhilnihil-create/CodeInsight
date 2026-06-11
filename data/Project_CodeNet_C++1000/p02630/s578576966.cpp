#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include <stdio.h>
#include<map>
//#include<set>
//#include<vector>
//#include<iomanip>
using namespace std;
long long arr[1000000];
int main(){

    long long n,m,sum=0;
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x;
        sum+=x;
        arr[x]++;
    }
    cin>>m;
    long long arr2[2];
    for(int i=0;i<m;i++){
        cin>>arr2[0]>>arr2[1];
        sum=sum-(arr[arr2[0]]*arr2[0])+(arr[arr2[0]]*arr2[1]);
        cout<<sum; if(i!=m-1){cout<<endl;}
        arr[arr2[1]]+=arr[arr2[0]];
        arr[arr2[0]]=0;
    }

    return 0;
}
