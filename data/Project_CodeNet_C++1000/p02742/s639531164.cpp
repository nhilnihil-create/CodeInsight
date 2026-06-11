#include<bits/stdc++.h>
using namespace std;
int main(){
long long  h,w;
cin >>h>>w;
long long  output =0;
if(h==1||w==1){
output =1;
}
else if(w%2==0){
output = (w/2)*h;
}else{
  
if(h%2==0){
output = (h*w)/2;
}else{
output = ((h-1)/2)*w + (w-1)/2 + 1;
}

}
  
cout << output <<endl; 
}