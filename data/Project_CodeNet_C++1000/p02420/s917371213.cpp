#include<string>
#include<iostream>
#include<cctype>
using namespace std;
int main(){
    string a[10000];
    int c,d,e;
    while(true){
        cin>>a[0];
        if(a[0]=="-"){
            break;
        }
        cin>>c;
        e=a[0].size();
        for(int i=1;i<=c;i++){
            cin>>d;
            a[i]=a[i-1].substr(d,e-d)+a[i-1].substr(0,d);
        }
        cout<<a[c]<<endl;
    }
    return 0;
}