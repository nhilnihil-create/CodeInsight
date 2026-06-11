#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long k;
    cin>>k;
    if(k%2==0 || k%5==0){
        cout<<-1<<endl;
        return 0;
    }
    long long a=7%k;
    for(int i=1;i<=k;i++){
        if(a==0) {
            cout<<i<<endl;
            return 0;
        }
        a=(a*10+7)%k;
    }
    cout<<-1<<endl;
    return 0;
}