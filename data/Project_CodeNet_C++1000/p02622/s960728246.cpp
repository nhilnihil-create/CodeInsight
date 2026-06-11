#include <iostream>

using namespace std;

int main()
{
    string x,y;
    int c=0;
    cin>>x>>y;
    for(int i=0;i<x.size();i++){
        if(x[i]!=y[i]){
            c++;
        }
    }
    cout<<c;

    return 0;
}
