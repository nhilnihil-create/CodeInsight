#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while(1){
        if(d<0){
            cout<<"No"<<endl;
            break;
        }
        //cout<<a<<" "<<b<<" "<<c<<endl;
        if(a>=b){
            b*=2;
        }else if(b>=c){
            c*=2;
        }else{
            cout<<"Yes"<<endl;
            break;
        }
        //cout<<"inoti"<<d<<endl;;
        d--;
    }
}
