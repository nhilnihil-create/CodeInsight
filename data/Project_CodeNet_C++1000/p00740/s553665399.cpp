#include <iostream>

using namespace std;

int main(){
    while(1){
        int n,m;
        cin>>m>>n;

        if(n==0&&m==0){
            return 0;
        }

        int a[m]={0};

        int owan=n;
        int now=0;
        
        for(int i=0;i<1000000;i++){
            now=i%m;

            if(owan==0){
                owan=a[now];
                a[now]=0;
            }else if(owan!=0){
                owan--;
                a[now]++;
            }

            // cout<<a[now]<<" "<<owan<<endl;
            if(a[now]==n){
                cout<<now<<endl;
                break;
            }   
        }
    }
}