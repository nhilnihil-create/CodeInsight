#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    // Your code here!
    double a;
    int b=0;
    cin>>a;
    for(int z=0;z<a;z++){
        if(z%2==0){
            b++;
        }
    }
    cout<<fixed<<setprecision(10)<<b/a<<endl;
}