#include <iostream>
using namespace std;
int main(void){
    string h;
    cin>>h;
    if (h.size()%2==1){
        cout<<"No";
    }
    else{
        for (int i = 0;i<h.size();i+=2){
            if (h.substr(i,2)!="hi"){
                cout<<"No";
                exit(0);
            }
        }
        cout<<"Yes";
    }
    
}
