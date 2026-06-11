#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string n;
    cin>>n;
    long sum = 0;

    for(char a : n){
        sum += int(a - '0');
    }

    if(sum%9 == 0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}