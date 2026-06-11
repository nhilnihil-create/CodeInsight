#include<iostream>
#include<cmath>

int main(){
 int n;
 std::cin >> n;
 int ind=-1;
 bool f=0;
 for(int i=n;i>=1;i--){
     if(floor(i*0.08+i)==n){
        f=1;
        ind=i;
        break;
     }
 }
 f==1?std::cout << ind : std::cout << ":(";
 return 0;
}
