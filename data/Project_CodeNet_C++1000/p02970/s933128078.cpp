#include<iostream>
#include <cmath>
using namespace std;

int main (){
    int N,D;
    double E;
    cin>>N>>D;
    E=N/(2*D+1.0);
    if(N%(2*D+1)==0){
        cout<<N/(2*D+1)<<endl;
    }
    else{cout<<ceil(E)<<endl;}
}