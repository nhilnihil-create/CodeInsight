#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            cout<<"No"<<endl;
            return 0;
        }else{
            if(a[i]!=a[i-1]){
                a[i]--;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}