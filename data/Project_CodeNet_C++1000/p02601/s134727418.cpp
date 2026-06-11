#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
IOS;
int a,b,c,k,flag=0;
cin>>a>>b>>c>>k;
    for(int i=0;i<k;i++){
        if(a<b*pow(2,i)&&a<c*pow(2,k-i)&&b*pow(2,i)<c*pow(2,k-i)){
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"Yes"<<"\n";
    else
        cout<<"No\n";
return 0;
}
