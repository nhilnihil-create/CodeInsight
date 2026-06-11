#include<iostream>
using namespace std;
int main(){
    int m,d,d1,d2,ans=0;
    cin>>m>>d;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=d;j++){
            d1=j%10,d2=j/10;
            ans+=(d1>1&&d2>1&&d1*d2==i);
        }
    }
    cout<<ans<<endl;
    return 0;
}