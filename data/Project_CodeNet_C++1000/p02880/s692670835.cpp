#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool> a(101);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            a[i*j]=true;
        }
    }
    if(a[n])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}