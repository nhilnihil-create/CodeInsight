#include <iostream>
#include<vector>
#include<map>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
#define Rrep(n) for(int i=n-1;i>=0;i--)
#define rep2(a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
int n;
cin>>n;
vector<int> vec(n-1), out(n,0);
rep(n-1){
    cin>>vec[i];
}
out[n-1]=vec[n-2];

int i=0;
for(i=n-2;i>=1;i--){
    if(vec[i-1]<=vec[i])
        out[i]=vec[i-1];
    else
        out[i]=vec[i];     
}

out[i]=max(out[i+1], vec[i]);

ll sum=0;
rep(n){
    sum+=out[i];
}
cout<<sum;
}


