#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin>>N;
    double sum=0,a;
    for(int i=0;i<N;i++){
        cin>>a;
        sum+=1.0/a;
    }
    sum=1.0/sum;
    cout<<sum<<endl;
    return 0;
}