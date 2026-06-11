#include<iostream>

using namespace std;

int main(){
    int A,B,C,K;
    bool flag=false;
    cin>>A>>B>>C>>K;
        for(int i=0;i<=K;++i){
            for(int j=0;j<=K;++j){
                for(int l=0;l<=K;++l){
                    int x=A*(1<<i),y=B*(1<<j),z=C*(1<<l);
                        if(x<y&&y<z&&i+j+l<=K)flag=true;
                }
            
            }
        }

            if(flag==true)cout<<"Yes";
            else cout<<"No";
}