#include<bits/stdc++.h>
#define lln long long int
using namespace std;
int main(){
    int n;
    cin>>n;
    double d=(double)n/1000;
    d=ceil(d);
    int ans=(d*1000)-n;
    cout<<ans<<endl;
}