#include <iostream>

using namespace std;

int main()
{
    int h,a;
    
    cin>>h>>a;
    
    int s = h/a;
    if(h%a!=0){
      s++;
    }
    cout<<s<<endl;
    

    return 0;
}
