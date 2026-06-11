#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;
 
int main(){

    long long N,A[200020]={},x=0,y=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    int l=0,r=N-1;
    while(l!=r){
        if(x<=y){
            x+=A[l];
            l++;
        }else{
            y+=A[r];
            r--;
        }
    }

    if(x<=y){
        x+=A[l];
        l++;
    }else{
        y+=A[r];
        r--;
    }

    cout <<abs(x-y)<<endl;
    
    return 0;

}
