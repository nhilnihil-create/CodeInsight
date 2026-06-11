#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w,n,c=1;cin>>h>>w>>n;
    int a=max(h,w);
    for(int i=a;i<n;i+=a)c++;
    cout<<c;
}