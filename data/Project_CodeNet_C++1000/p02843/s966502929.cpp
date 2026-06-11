#include <iostream>
using namespace std;

int main(void){
    int x;
    cin>>x;
    cout<<((x/100 * 5 < x%100)?0:1)<<endl;
}