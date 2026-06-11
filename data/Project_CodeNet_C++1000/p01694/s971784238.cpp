#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;
int main(){
    int n,cnt;
    string s;
    bool l=0,r=0;
    int a=-1;
    for(;;){
        cin>>n; 
        if(n==0)
            return 0;
        cnt=0;
        a=-1;
        rep(i,n){
            cin>>s;
            if(s=="lu"){
                l=1;
                if(a==2){
                    cnt++;
                }
                a=1;
            }else if(s=="ru"){
                r=1;
                if(a==1){
                    cnt++;
                }
                a=2;
            }else if(s=="ld"){
                l=0;
                if(a==4){
                    cnt++;
                }
                a=3;
            }else{//rd
                r=0;
                if(a==3){
                    cnt++;
                }
                a=4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
