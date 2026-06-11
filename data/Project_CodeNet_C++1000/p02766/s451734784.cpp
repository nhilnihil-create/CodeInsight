#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int cnt=0;
    while(n>0){
        cnt++;
        n/=k;
    }
    cout<<cnt<<endl;
    return 0;
}