#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
    int a;
    cin>>a;
    a=a%10;
    if(a==3){
        cout<<"bon"<<endl;
    }
    else if(a<=1||a==6||a==8){
        cout<<"pon"<<endl;
    }
    else{
        cout<<"hon"<<endl;
    }
    return 0;
}
