#include <iostream>
#include<vector>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(b==1){
        cout<<0;
        return 0;
    }
    int sum=a;
    int cnt=1;
    while(sum<b){
        sum+=(a-1);
        cnt+=1;
    }
    cout<<cnt;
}
