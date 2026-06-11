#include <iostream>
#include <string>
using namespace std;

int main(){
    long long int n,m=1;
    string s;
    cin>>n>>s;
    for(int i=0;i<4;i++){
        if(i==0){
            m=((int)(s[i])-'0')*100;
            
        }
        else if(i==1){
            continue;
        } else if(i==2){
             m=m+(((int)(s[i])-'0')*10);
        }else
        {
             m=m+((int)(s[i])-'0');
        }
        
    }
    
    cout<<(n*m)/100;

    return 0;
}