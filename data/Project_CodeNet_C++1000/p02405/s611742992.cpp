#include <iostream>
using namespace std;
int HW(int H,int W);
int main(void){
int h,w,x;
while(1){
cin>>h>>w;
if(h==0 && w==0){
break;
}
x=HW(h,w);
cout<<endl;
}
return 0;
}

int HW(int H,int W){
int i=1;
for(int a=0;a<H;a++){
int ii=1;
    for(int b=0;b<W;b++){
    if(i%2==1){
        if(ii%2==1){
            cout<<"#";
        }else{
            cout<<".";
        }
    }else{
        if(ii%2==1){
            cout<<".";
        }else{
            cout<<"#";
        }
    }
    ii+=1;
    }
i+=1;
cout<<endl;
}
return 0;
}