#include<bits/stdc++.h>
using namespace std;
int main(){
    int  n;
    cin>>n;
    int a[n];
    int counter=0;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n-2;i++){
    if((a[i+1]>a[i]&& a[i+1]<a[i+2])||(a[i+1]<a[i] && a[i+1]>a[i+2])){
        counter=counter+1;
    }
}
cout<<counter<<endl;
}
