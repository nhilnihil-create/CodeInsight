#include <iostream>
#include <algorithm>
using namespace std;
int H,N;
long long sum = 0;
int main(){
    cin>>H>>N;
    int A[N];
    for(int i =0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    if(sum>=H){cout<<"Yes";}
    if(sum<H){cout<<"No";}
}
