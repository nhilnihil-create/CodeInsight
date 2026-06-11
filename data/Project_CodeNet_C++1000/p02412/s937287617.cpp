#include <iostream>
using namespace std;
int main(){
    int n,x,cnt;
    int iniI,iniJ,inik;
    while(cin>>n>>x,n!=0||x!=0){
        cnt=0;
        iniI=1; 
        for(int i=iniI;i<=n;i++){
            iniI=i+1;
            iniJ=i+1; 
            for(int j=iniJ;j<=n;j++){
                iniJ=j+1;
                inik=j+1;
                for(int k=inik;k<=n;k++){
                    inik=k+1;
                    if((i+j+k)==x){
                        cnt++;
                        //cout<<"○"<<i<<"+"<<j<<"+"<<k<<"=="<<x<<endl;
                    }
                    /*else{
                        cout<<"×"<<i<<"+"<<j<<"+"<<k<<"!="<<x<<endl;
                    }*/
                }
            }
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}
