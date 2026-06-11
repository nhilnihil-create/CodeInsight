#include<iostream>
 
using namespace std;
 
int main(){
    int a,b,c,N,ans=0;
    string S,T;
    cin >> a >> b >> c;
    cout << max(c-(a-b),0) << endl;
}
