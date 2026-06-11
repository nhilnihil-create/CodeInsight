#include <iostream>
using namespace std;
int main(){
    int a, b,c;
    cin >>a >> b>> c;

    if(1<=a && b && c <=9){

        if( a== b && a==c){
            cout<<"No"<<endl;
        }
    else if (a==b || a==c || b==c)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    }


   return 0;
 }
