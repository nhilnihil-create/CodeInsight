#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include <stdio.h>
#include<map>
#include<set>
#include<vector>
#include<iomanip>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a=0,w=0,t=0,r=0;
    string x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x[0]=='A'){a++;}
        else if(x[0]=='W'){w++;}
        else if(x[0]=='T'){t++;}
        else {r++;}
    }
    cout<<"AC x "<<a<<endl;
    cout<<"WA x "<<w<<endl;
    cout<<"TLE x "<<t<<endl;
    cout<<"RE x "<<r;

return 0;
}
