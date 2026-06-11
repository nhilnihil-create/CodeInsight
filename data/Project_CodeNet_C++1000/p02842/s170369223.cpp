#include <bits/stdc++.h>
using namespace std;


int main(){


 long long n;
 cin>>n;

 int enable = 0; long long price=0;

 for(long long i=1;i<=n;i++){


    if( (int)(i*1.08) == n){

        enable = 1;
        price = i;
         break;
        }
 }

  //cout<<price<<" "<<enable<<endl;

 if(enable == true)
    cout<<price<<endl;
 else
    cout<<":("<<endl;

return 0;
}