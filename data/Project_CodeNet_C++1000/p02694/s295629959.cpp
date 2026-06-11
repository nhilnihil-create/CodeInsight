#include <iostream>
using namespace std;
int main(void){
    long long x;
    cin>>x;
    long long n=100;
    int year=0;
    while(n<x)  {
        n+=n/100;
        ++year;
    }
    cout<<year<<endl;
    
}
