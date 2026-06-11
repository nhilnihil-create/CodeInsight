#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d, cnt=0;
    cin>>a>>b>>c>>d;

    while(true){
        if(cnt%2==0){
            c=c-b;
        }else{
            a=a-d;
        }
        if(c<=0){
            cout<<"Yes"<<endl;
            return 0;
        }else if(a<=0){
            cout<<"No"<<endl;
            return 0;
        }
        cnt++;
    }
}
