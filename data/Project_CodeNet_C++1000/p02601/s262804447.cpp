#include<bits/stdc++.h>
#define li long long int
using namespace std;
int main(){
    li a,b,c;
    cin>>a>>b>>c;
    li k;
    cin>>k;
    while(k!=0&&b<=a)
    {
        b=b*2;
        k--;
    }
    if(b<=a){
        cout<<"No"<<endl;
        return 0;
    }
    while(k!=0&&c<=b){
        c=c*2;
        k--;
    }
    if(c<=b){
        cout<<"No"<<endl;
        return 0;
    }
    if(c>b&&b>a)
    cout<<"Yes"<<endl;
    
}