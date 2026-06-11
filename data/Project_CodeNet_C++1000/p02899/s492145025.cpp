#include <iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
int n,k,count=0;
cin>>n;
vector<int> inp(n,-1),out(n,-1);
for(int i=0;i<n;i++){
    cin>>inp[i];
    inp[i]--;
}

for(int i=1;i<=n;i++){
    out[inp[i-1]]=i;
}

rep(n){
    cout<<out[i]<<" ";
}

}
