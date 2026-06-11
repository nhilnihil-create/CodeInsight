#include<iostream>

using namespace std;

long long a[200005];
int b[200005];
int main(){
    int n;
    long long k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];b[i]=0;
    }
    int i=1, x=1;
    while( k--){
        b[i]=x;
        i=a[i];
        if(b[i] >= 1){
            k=k%(x-b[i]+1);
        }
        x++;
    }
    cout<<i<<endl;
    return 0;
}