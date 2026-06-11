#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    string a,b;
    int c=0;
    cin>>a>>b;
    if(a[0] == b[0]){
        c++;
    }
    if(a[1] == b[1]){
        c++;
    }
    if(a[2] == b[2]){
        c++;
    }
    cout<<c;

}