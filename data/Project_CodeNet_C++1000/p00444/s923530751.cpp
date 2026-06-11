#include<iostream>

using namespace std;

int main(void){
    
    int n,otsuri,count;
    const int money[6]={1,5,10,50,100,500};

    while(cin>>n,n){
            
        otsuri=1000-n;
        count=0;
        for(int i=5;i>=0;i--){
            while(otsuri>=money[i]){
                otsuri=otsuri-money[i];
                count++;
            }   
        }   
        cout<<count<<endl;
    }   


}