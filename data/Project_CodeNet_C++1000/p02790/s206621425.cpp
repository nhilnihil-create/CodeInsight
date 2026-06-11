#include<iostream>
#include<iomanip>
using namespace std;
main()
{

             long long a,b,i,j;
             cin>>a>>b;
             if(a>b){
                for(i=0;i<a;i++){
                                cout<<b;
                }
             }
             else{
                for(i=0;i<b;i++){
                                cout<<a;
                }
             }
            cout<<endl;
}
