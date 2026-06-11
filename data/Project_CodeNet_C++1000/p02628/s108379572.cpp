#include <iostream>

using namespace std;

int main()
{
int K,N,p[1000],temp,sum=0;
cin>>N>>K;
for( int i=0;i<N;i++){
    cin>>p[i];
}
for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
        if(p[j]<p[i]){
            temp= p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
}
for(int i=0;i<K;i++){
    sum=sum+p[i];
}
cout<<sum;
    return 0;
}
