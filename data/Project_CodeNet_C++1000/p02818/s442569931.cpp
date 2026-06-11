#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    long long a,b,k;
    cin>>a>>b>>k;
    if(k<=a)cout<<a-k<<" "<<b<<endl;
    else if(a<k&&k<=a+b)cout<<0<<" "<<a+b-k<<endl;
    else cout<<0<<" "<<0<<endl;
    return 0;
}