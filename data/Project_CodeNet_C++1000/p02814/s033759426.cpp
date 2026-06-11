#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long int gcd(long long int a,long long int b){
    if(!b)return a;
    return gcd(b,a%b);
}
int main(){
    long long int N,M;
    cin>>N>>M;
    long long int now=1;
    for(int i=0;i<N;i++){
        long long int a;
        cin>>a;
        a/=2ll;
        if(i==0){
            now=a;
            //printf("[%lld][%lld]\n",now,a);
            continue;

        }
        long long int papapa=(a*now)/gcd(a,now);
        if(M<papapa){
            cout<<0<<endl;
            //printf("[%lld][%lld] [%lld]\n",now,a,papapa);
            return 0;
        }
        if((papapa/now)%2==0||(papapa/a)%2==0){
            cout<<0<<endl;
            //printf("[%lld][%lld] [%lld]\n",now,a,papapa);
            return 0;
        }
        //printf("[%lld][%lld] [%lld]\n",now,a,papapa);
        now=(a*now)/gcd(a,now);
    }
    cout<<M/now-(M/(now*2ll))<<endl;
    return 0;
}
