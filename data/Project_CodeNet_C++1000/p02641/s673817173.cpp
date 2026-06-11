#include<bits/stdc++.h>
using namespace std;
int main(void){
    int X,N,i,j;
    cin>>X>>N;
    if(N==0){
        cout<<X<<endl;
        return 0;
    }
    vector<int>p(N);
    for(i =0;i<N;i++){
        cin>>p[i];
    }

    //sort p from smallest to biggest
    for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
            if(p[j]<p[j-1])swap(p[j],p[j-1]);
        }
    }
    int gap = 100;
    int ans;
    j = 0;
    //find the num(not incleded in p)with the smallest gap with X
    for(i=-1;i<=(X+p[N-1]);i++){
        if(i == p[j]){
            j++;
            continue;
        }else{
            if(gap>abs(i-X)){
                gap = abs(i-X);
                ans = i;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}