#include <iostream>

using namespace std;

int main()
{
string x="";
string y="";
int count=0;
cin>>x>>y;

for(int i=0;i<x.size();i++){
if(x[i]!=y[i]){
    count++;
}

}
cout<<count;

    return 0;
}
