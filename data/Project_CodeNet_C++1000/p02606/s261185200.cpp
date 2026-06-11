#include <iostream>
#include <vector>
using namespace std;
int main(){
    int l,r,d;
    cin>>l; cin>>r; cin>>d;
    int i=l; int cnt=0;
    while(i<=r){
        if(i%d==0){
            cnt++; i++;
        } else i++;
    }
    cout<<cnt<<endl;
}