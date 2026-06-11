#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

long long gcd(int x, int y){
    if(x<y)swap(x,y);
    if(x%y==0){
        return y;
    }else{
        return gcd(y,x%y);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    long long g=gcd(n,k);
    cout<<n/g*k<<endl;
    return 0;
}