#include <bits/stdc++.h>
#include <math.h>
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
    ABC134();
}

void ABC134(){
    int n,d;
    cin>>n>>d;
    if(n%(2*d+1)==0)cout<<n/(2*d+1)<<endl;
    else cout<<n/(2*d+1)+1<<endl;
}