#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    char c[10]={'0','1','2','3','4','5','6','7','8','9'};
    int b;
    while(true){
    b=0;
    cin>>a;
    if(a=="0"){
        break;
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<10;j++){
            if(a[i]==c[j]){
                b += j;
            }
        }
    }
    cout<<b<<endl;
    }
    return 0;
}