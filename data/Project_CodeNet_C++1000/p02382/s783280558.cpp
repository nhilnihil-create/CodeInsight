#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int n;
    int *x,*y;
    cin>>n;
    x=new int [n];
    if (x==NULL){
        cout<<"Error!"<<endl;
        return -1;
    }
    y=new int [n];
    if (y==NULL){
        cout<<"Error!"<<endl;
        delete [] x;
        return -1;
    }
    int i;
    
    for (i=0;i<n;i++) cin>>x[i];
    for (i=0;i<n;i++) cin>>y[i];
    
    cout<<fixed<<setprecision(6);
    double d;
    for (int p=1;p<=3;p++){
        d=0;
        for (i=0;i<n;i++){
            d+=pow(abs(x[i]-y[i]),(double)p);
        }
        d=pow(d,1.0/p);
        cout<<d<<endl;
    }
    d=0;
    //?????§????????§????????¢
    for (i=0;i<n;i++)
        if (abs(x[i]-y[i])>d) d=abs(x[i]-y[i]);
    cout<<d<<endl;
    delete [] x;
    delete [] y;
    return 0;
}