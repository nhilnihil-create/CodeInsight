#include <iostream>
#include <string>
using namespace std;

const string weather[3] = {"Sunny","Cloudy","Rainy"};

int main(){
    string s;
    int i,k;
    cin >> s;
    for(i=0;i<3;i++){
        if(s==weather[i]){
            k=i;
            break;
        }
    }
    if (k==2){
        k=0;
    }else{
        k=k+1;
    }
    cout << weather[k];
}