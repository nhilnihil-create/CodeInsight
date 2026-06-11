#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,k,sum=0;
    cin>>a>>b>>c>>k;
    while(k>0){
        if(a>=k && k>0)
        {
            sum+=k;
            break;
        }
        else if(a<k && k>0)
        {
            sum+=a;
            k-=a;
        }
        if(b>=k && k>0){
            break;
        }
        else if(b<k && k>0){
            k-=b;
        }
        if(c>=k && k>0){
            sum-=k;
            break;
        }
        else if(c<k && k>0){
            sum-=c;
            break;

        }
    }
    cout<<sum<<endl;
}