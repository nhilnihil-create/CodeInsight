#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    cin>>A>>B;

    int K;
    K=(A+B)/2;

    int R;
    R=(A+B)%2;

    if(R==0){cout<<K<<endl;}
    else{cout<<"IMPOSSIBLE"<<endl;}
}
