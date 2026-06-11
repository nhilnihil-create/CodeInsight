#include <iostream>

using namespace std;

int main(){
    int s;
    cin>>s;
    int x=s/2;
    if(s%2==0)
        x = s/2;
    else
        x = x+1;
    cout<<x<<endl;
}