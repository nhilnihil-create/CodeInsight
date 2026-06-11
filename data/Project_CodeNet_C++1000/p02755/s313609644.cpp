#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=1000000000;i++){
        int c=i*0.08;
        int d=i*0.1;
        if(c==a&&d==b){
            cout<<i<<"\n";
            return(0);
        }
    }
    cout<<"-1\n";
    return(0);
}