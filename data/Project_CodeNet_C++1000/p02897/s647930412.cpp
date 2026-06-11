#include<iostream>
using namespace std;
int main(){
    double n;
    cin>>n;
    double cnt=0;
    for(int i=0;i<=n;i++){

        if(i%2==1){
            cnt++;
        }
    }
    // cout<<cnt;
    cout<<cnt/n;
}
  
