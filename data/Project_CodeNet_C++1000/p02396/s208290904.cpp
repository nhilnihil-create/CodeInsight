#include<iostream>
using namespace std;
int main(){
    int n=1;
    int x;
    while(n<=10000){
        cin>>x;
        cout<<"Case "<<n<<": "<<x<<endl;
        n+=1;
        if(x==0)break;
    }
    return 0;
}
