#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >>n;
int num = n/1.08; 
int flag = 0;
for(int i = num -10;i<num + 10;i++){
int price = i*1.08;

if(price==n){
cout << i <<endl;
flag++;
break;
}
}  
if(flag==0){
cout <<":("<<endl;

}  
}