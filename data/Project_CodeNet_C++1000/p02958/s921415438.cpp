#include<iostream>
using namespace std;
int main(){
    int n,a,i,c=0;
    cin>>n;
    for(i=1;n--;i++){
        cin>>a;
        if(i!=a){
            c++;
        }
    }
    if(c>=0 && c<=2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}