#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long int n,a,b;
    cin >> n >> a>> b;
    long long int amari=n%(a+b);
    if(amari<=a){
        cout << n/(a+b)*a+amari << endl;
    }else{
        cout << n/(a+b)*a+a << endl;
    }
    
    return 0;
    
}