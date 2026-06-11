#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int A[3]; cin>>A[0]>>A[1]>>A[2];
    int sum=A[0]+A[1]+A[2];

    if(sum<22){
        cout<<"win"<<endl;
    }else{
        cout<<"bust"<<endl;
    }
}
