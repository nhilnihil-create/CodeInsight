#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int a,b[10000000];
double sum=0,sum2=0,avg=0;
int main(){
    while(true){
        cin>>a;
        sum=0;
        sum2=0;
        if(a==0){
            break;
        }
        for(int i=0;i<a;i++){
            cin>>b[i];
            sum += b[i];
        }
        avg=sum/a;
        for(int i=0;i<a;i++){
            sum2 += pow(avg-b[i],2);
        }
        sum2 /= a;
        cout<<fixed<<setprecision(30)<<sqrt(sum2)<<endl;
    }
    return 0;
}