#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string array;
    cin>>array;
    int sum=0;
    for(int i=0;i<array.length();i++){
        sum+=array[i]-'0';
        
    }
    if(sum%9==0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}

