#include <iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
#define rep2(i,a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
int n,k,count=0;
cin>>n>>k;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(a>=k)
    count++;
}
cout<<count;
}
