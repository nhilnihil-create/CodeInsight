#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin>>s;
    string r="Sunny";
    
    if(s=="Sunny"){
        r="Cloudy";
    }else if(s=="Cloudy"){
        r="Rainy";
    }
    cout<<r<<endl;
    return 0;
}
