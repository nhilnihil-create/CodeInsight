#include <iostream>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
  int l= b/n;
  l=l*n;
    if(a<=l){
        cout<<"OK"<<endl;
    }
    else{
        cout<<"NG"<<endl;
    }

    return 0;
}