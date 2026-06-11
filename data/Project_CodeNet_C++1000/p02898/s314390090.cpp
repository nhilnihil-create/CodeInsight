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
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        if(h>=k)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}