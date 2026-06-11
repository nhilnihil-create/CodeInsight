#include<bits/stdc++.h>
using namespace std;


int main(){
    int a,b;
    cin>>a>>b;

    int s=0;

    if(b==1)
    {
        cout<<0<<endl;
        return 0;
    }

    for(int i=1 ;  ; i++){
        s=s+a;
        if(s>=b){
            cout<<i<<endl;
            break;
        }


        s--;

    }


}
