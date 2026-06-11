#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n,n){
            vector<int> isprime(2*n+1,1);
            isprime[0]=0;
            isprime[1]=0;
                    for(int i=1;i<=2*n;i++)
                        if(isprime[i]){
                            for(int j=i*2;j<=2*n;j+=i)
                                isprime[j]=0;


                        }

                    int cnt=0;
                    for(int i=n+1;i<=2*n;i++)
                    cnt+=isprime[i];
            cout<<cnt<<endl;}


}