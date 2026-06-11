#include<iostream>
using namespace std;
int Tim(int a,int b){
    return (b==0) ? a:Tim(b,a%b);
}
int main(){
    int a,b;
    cin >>a>>b;
    cout <<Tim(a,b)<<endl;
    return 0;
}