#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    int a,b;
    double f;
    cin>>a>>b;
    f=(double)a/b;
    cout<<a/b<<" "<<a%b<<" "<<fixed<<f<<endl;
}