#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
cin >>a>>b;
int output=0;
int count=1;
while(count<b){
if(b==1){
break;
}
count--;
count += a;
output++;
}
cout << output <<endl;
}