#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a;
    for(int i=1;i<=5;i++){
        cin>>a;
        if(a==0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}