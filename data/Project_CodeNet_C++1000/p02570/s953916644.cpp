#include<bits/stdc++.h>
using namespace std;
int main(){
    int d,t,s;
    cin>>d>>t>>s;
    if(double(d)/double(s)<=t){
        std::cout << "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;
    }
}