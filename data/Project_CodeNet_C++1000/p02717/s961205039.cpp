#include<bits/stdc++.h>
using namespace std;
int main(){

int a[3];
int temp=0;
for(int i=0;i<3;i++){
    
    
    cin>>a[i];
}

temp=a[0];
a[0]=a[1];
a[1]=temp;

temp=a[0];
a[0]=a[2];
a[2]=temp;

for(int i=0;i<3;i++){
    
    
    cout<<a[i]<<" ";
}
return 0;
}
