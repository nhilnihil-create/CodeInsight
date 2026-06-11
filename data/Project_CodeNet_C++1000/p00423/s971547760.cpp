#include <iostream>   
using namespace std;     
int main() {     
    while(1){         
        int a[10000]={0},b[10000]={0},n=0,sum_a=0,sum_b=0;         
        cin>>n;         
        if(!n)break;                 
        for(int i=0;i<n;i++){             
            cin>>a[i]>>b[i];             
            if(a[i]>b[i]){                 
                sum_a+=(a[i]+b[i]);            
            }else if(a[i]<b[i]){                
                sum_b+=(a[i]+b[i]);                 
            }else{                 
                sum_a+=a[i];                 
                sum_b+=b[i];             
            }          
        }         
        cout<<sum_a<<" "<<sum_b<<endl;     
    }             
    return 0;
}