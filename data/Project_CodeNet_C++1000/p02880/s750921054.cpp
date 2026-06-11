#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin>>n;
    bool b=false;
    for(int i=1;i<10;i++){
        for(int j=0;j<10;j++){
            if(i*j==n){
                b=true;
            }
        }
    }
    string s;
    if(b){
        s="Yes";
    }else{
        s="No";
    }
    cout<<s<<endl;
}