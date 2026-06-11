#include<iostream>

using namespace std;
int main()
{
    int n,x;
    cin>>n;
    if (n%2 == 0){
    x = (n/2)-1;
    }
    else{
        x = n/2;
    }
    cout<<x<<endl;
}


