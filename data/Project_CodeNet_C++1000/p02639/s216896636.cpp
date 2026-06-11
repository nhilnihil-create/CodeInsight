#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main(){
    int sum=10;
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        sum-=a;
    }
    cout<<sum+5<<endl;
}