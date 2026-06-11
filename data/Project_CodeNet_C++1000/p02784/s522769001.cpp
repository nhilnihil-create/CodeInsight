#include<bits/stdc++.h>
using namespace std;
int main(){
int x,y,z;
cin>>x>>y;
int arr[y];

for(int i=0;i<y;i++){
    cin>>arr[i];
}
sort(arr,arr+y);

for(int i=0;i<y;i++){
        if(x>0){
   int r = x-arr[i];
   x=r;
}
}
if(x>0){
    cout<<"No";
}
else{
    cout<<"Yes";
}
}
