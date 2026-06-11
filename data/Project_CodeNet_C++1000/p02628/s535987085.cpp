#include <iostream>

using namespace std;

int main()
{
int K,N,p[1000],Temp,min=0;
cin>>N>>K;
for( int i=0;i<N;i++){
    cin>>p[i];
}
for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
        if(p[j]<p[i]){
            Temp= p[i];
            p[i]=p[j];
            p[j]=Temp;
        }
    }
}
for(int i=0;i<K;i++){
     min=min+p[i];
}
cout<<min;
    return 0;
}