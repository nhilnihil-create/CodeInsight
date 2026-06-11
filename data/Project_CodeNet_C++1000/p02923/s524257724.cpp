#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int A[n];
for(int i=0 ; i<n ; i++) cin>>A[i];
int len = 0;
int mx = 0;
for(int i=0 ; i<n-1 ; i++){
    if(A[i]>=A[i+1]) len++ , mx = max(mx , len);
    else
        len = 0;
}
cout<<mx<<endl;
}
