#include<iostream>
using namespace std;
int main(){
    int h,w,i,j;
    for(;;){
    cin>>h>>w;
    if(h==0)exit(0);
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if((i+j)%2){cout<<".";}else{cout<<"#";}
        }
        cout<<endl;
    }
    cout<<endl;
}
return 0;
}