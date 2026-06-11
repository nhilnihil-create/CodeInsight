#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin>>a>>b;
    int x=0;
    while(x*(a-1)+1<b){
        x++;
    }
    cout<<x<<endl;
}
