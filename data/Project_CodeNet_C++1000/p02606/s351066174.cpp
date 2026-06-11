#include <iostream>
using namespace std;

int main() {
    int l,r,d,i,count=0;
    
    cin >> l >> r >>d;
    
    for(i=l;i<=r;i++)
    {
       
        if(i%d==0){
          count++;
        }
        
    }
    cout<<count;
   
}
