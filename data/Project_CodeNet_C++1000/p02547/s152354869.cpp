#include <iostream>
using namespace std ;
int main(int argc, const char * argv[]) {
    int n,c=0,a,b;
    cin>>n;
    for (int i =0 ; i< n ; i++)
    {
        cin>>a>>b;
        if(a==b)
            c++;
        else
            c=0;
        if(c==3){
             cout<<"Yes"<<endl;
             return 0;
        }
           
    }
    cout<<"No"<<endl;
    return 0;
}
