#include <iostream>
using namespace std;
void ABC130(void);
void ABC131(void);
void ABC132(void);
void ABC133(void);
void ABC134(void);
void ABC135(void);
void ABC136(void);
void ABC137(void);
void ABC138(void);
void ABC139(void);

int main(void){
    ABC136();
}

void ABC136(){
    int a,b,c;
    cin>>a>>b>>c;
    if(c<=(a-b))cout<<0<<endl;
    else cout<<c-(a-b)<<endl;
}