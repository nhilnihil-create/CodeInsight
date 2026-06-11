#include <bits/stdc++.h>
using namespace std;
#define s 1005
int main()
{int a,b,c,d;
int arr[s][s];
cin>>a>>b>>c>>d;
for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
       if(i<d){
       if(j<c){
           cout<<1;
       }
       else{
           cout<<0;
       }
    }
        else{
            if(j<c){
                cout<<0;
            }
            else{
                cout<<1;
            }
    }
        
    }
    cout<<'\n';
}


    return 0;
}
