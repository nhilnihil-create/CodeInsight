#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    long long int x=100,c=0,X;
    cin>>X;
    while(x<X){
        x+=x/100;
        c++;
    }
    cout<<c<<"\n";
}