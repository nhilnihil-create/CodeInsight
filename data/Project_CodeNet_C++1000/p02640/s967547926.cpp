#include<iostream>
using namespace std;
int main(){
    int i,X,Y,c=0;
    cin >> X >> Y;
    for(i=0;i<=X;++i){
        if((2*i+4*(X-i))==Y){
            ++c;
        }
    }
    if(c>0){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

}