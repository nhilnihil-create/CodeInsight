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
int main(){

    long long n,ans=0;
    cin>>n;
    map<string,long long>arr;
    char x[11];
    for(int i=0;i<n;i++){
        cin>>x;
        sort(x,x+10);
        arr[x]++;
        ans+=arr[x]-1;
    }
    cout<<ans;
    return 0;
}

