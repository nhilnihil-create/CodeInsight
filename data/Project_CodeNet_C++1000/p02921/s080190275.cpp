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
    ABC139();
}

void ABC139(){
    int i,n=0;
    string s,t;
    cin>>s>>t;
    for(i=0;i<=2;++i){
        if(s[i]==t[i])++n;
    }
    cout<<n<<endl;
}