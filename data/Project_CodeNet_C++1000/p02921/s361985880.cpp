#include<iostream>
using namespace std;
int main(){
    char a[4],b[4];
    int tedad=0;
    cin>>a;
    cin>>b;
    if(a[0]==b[0]){
        tedad++;
    }
    if(a[1]==b[1]){
        tedad++;
    }
    if(a[2]==b[2]){
        tedad++;
    }
    cout<<tedad;
}
