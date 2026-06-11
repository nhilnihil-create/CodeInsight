#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    int sum=0;

    for(int i=1;i<=n;i++){
        int b=i;
        int sum2=1;

        while(i>0){ 
            i/=10;
            if(i>0){
                sum2++;
            }
        }
        if(sum2%2==1) sum++;
        i=b;
    }

    cout<<sum<<endl;
}