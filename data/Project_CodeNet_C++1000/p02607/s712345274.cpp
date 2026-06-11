#include <iostream>

using namespace std;

int main()
{
    int n,counter=0;
    cin>>n;
    for(int i=1 ; i<=n ; i++){
            int a;
       cin>>a;
       if(a%2==0){
        counter+=0;
       }
       else{
        if(i%2==0){
            counter+=0;
        }
        else{
            counter+=1;
        }
       }

    }

   cout<<counter;


}
