#include<iostream>
using namespace std;
int main(){
    string x , y , c;
    cin>>x>>y;
    int a , b; cin>>a>>b;
    cin>>c;
    if(c==x)
        cout<<--a<<" "<<b<<endl;
    else cout<<a<<" "<<--b<<endl;

    return 0;
}
