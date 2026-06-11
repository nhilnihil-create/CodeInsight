#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int k,a,b;
    cin>>k;
    cin>>a>>b;
    if(a%k==0||b%k==0){
    	cout<<"OK";
    }else if((((a/k)+1)*k)<b){
    	cout<<"OK";
    }else cout<<"NG";
    return 0;
}
