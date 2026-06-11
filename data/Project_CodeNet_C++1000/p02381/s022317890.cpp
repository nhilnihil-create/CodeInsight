#include<iostream>
#include<cmath>
using namespace std;

int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        double s[n],m=0.0,sigma=0.0;
    
        for(int i=0;i<n;i++){cin>>s[i];m+=s[i];}
        m=m/n;
        for(int i=0;i<n;i++){
            sigma+=(s[i]-m)*(s[i]-m);
        }
        sigma=sigma/double(n);
        cout<<sqrt(sigma)<<endl;
    }
    return 0;
}
