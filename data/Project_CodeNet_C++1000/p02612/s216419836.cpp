#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    
    int use = (n/1000) + (n%1000 ? 1 : 0);
    cout<< use*1000 - n ;
}

