#include<iostream>
using namespace std;

int main(void){
        int H1,M1,H2,M2,K;
        int cul;
        int ans;
        cin>>H1>>M1>>H2>>M2>>K;

        cul=(H2*60+M2)-(H1*60+M1);

        if(cul>K){
                ans=cul-K;
        }else{
                ans=0;
        }
        cout<<ans<<endl;
        return 0;
}
