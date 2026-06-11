#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    //a<=x<=b,c<=y<=d  x*y
    long s=(long)b*d,t=(long)a*c;
    if(s<t){
        s=t;
    }
    t=(long)a*d;
    if(s<t){
        s=t;
    }
    t=(long)b*c;
    if(s<t){
        s=t;
    }
    cout<<s<<endl;
    
    return 0;
}