#include <bits/stdc++.h>
using namespace std;

bool Harmony(long A, long B){

    if((A+B)%2==0)
        return true;
    else
        return false;

}
int main(){

    long a,b;
    cin>>a>>b;

    if(Harmony(a,b))
        cout<< (a+b)/2<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;


    return 0;
}