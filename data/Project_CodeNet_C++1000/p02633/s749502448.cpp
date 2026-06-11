#include<bits/stdc++.h>
using namespace std;

int main(){
    int temp,j=360;
    cin>>temp;
    while(j%temp!=0){
        j+=360;
    }
    cout<<j/temp<<endl;
    return 0;
}
