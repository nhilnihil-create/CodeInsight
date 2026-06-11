#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,d,n,count;
    double q;
    while(true){
        count=0;
        cin>>a>>d>>n;
        if(a==0&&d==0&&n==0){
            break;   
        }else{
            a-=d;
            while(count!=n){
                a+=d;
                if(a>3){
                    q=sqrt(a);
                    bool r=true;
                    for(int j=2;j<=q;j++){
                        if(a%j==0){
                            r=false;
                            break;
                        }
                    }
                    if(r==true){
                        count++;
                    }
                }else if(a==2||a==3){
                    count++;
                }
            }
            cout<<a<<endl;
        }
    }
    return 0;
}