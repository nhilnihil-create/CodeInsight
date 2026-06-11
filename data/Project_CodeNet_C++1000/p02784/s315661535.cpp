#include<bits/stdc++.h>
using namespace std;

int main(){

    int h,n;
    int a;

    cin>>h;
    cin>>n;


   for(int i=0; i<n; i++){
    cin>>a;
    h=h-a;
   }
if(h>0)
    cout<<"No";
else
    cout<<"Yes";
    return 0;


}
