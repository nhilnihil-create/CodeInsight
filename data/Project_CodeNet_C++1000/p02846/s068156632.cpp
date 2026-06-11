#include<iostream>

using namespace std;

void swap(long long int* a, long long int* b){
    long long int t;
    t=*a;
    *a=*b;
    *b=t;
}

int main(){
    long long int T1,T2,A1,A2,B1,B2,ans,diff,top;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    //AとBでT1の速度が速い方を、Aに
    if(A1<B1){
        swap(&A1,&B1);
        swap(&A2,&B2);
    }
    diff = B1*T1+B2*T2 - A1*T1 - A2*T2;
    if(diff<0){
        cout <<0<<endl;
    }
    else if(diff==0){
        cout<<"infinity"<<endl;
    }
    else{
        top = A1*T1-B1*T1;
        if(top%diff==0){
            ans = (top/diff)*2;
        }
        else{
            ans = (top/diff)*2+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
