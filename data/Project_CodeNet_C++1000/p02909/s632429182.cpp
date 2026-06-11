#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string S;
    cin>>S;
    if(S[0]=='S')
    cout<<"Cloudy"<<endl;
    else if(S[0]=='C')
    cout<<"Rainy"<<endl;
    else
    cout<<"Sunny"<<endl;
    return 0;
}
