#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int N,i,n,a[100001]={0},b[100001]={0},t;
    cin>>N;
    for(i=1;i<=N;i++){
        cin>>n;
        a[i]=n;
    }
    
    for(i=1;i<=N;i++){
        t=a[i];//t=2
        b[a[t]]=t;//b[a[2]]=2
       // cout<<a[i]<<endl;
    }
 
    for(i=1;i<=N;i++){
        cout<<b[i]<<" ";
    }
}
