#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long a[n];
    map<long long,long long>d;
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        d[a[i]]++;
        if(d[a[i]]>1)flag=false;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}