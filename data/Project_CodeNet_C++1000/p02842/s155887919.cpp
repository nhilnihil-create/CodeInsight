#include<iostream>
using namespace std;

int main() {
    int N;
    cin>>N;
    int x=(N+1)*100/108;
    if ((108*x)/100==N)
        cout<<x<<endl;
    else
        cout<<":("<<endl;
    return 0;
    }
