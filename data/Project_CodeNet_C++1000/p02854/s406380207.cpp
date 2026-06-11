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

    long long N,A[200020]={},x=0,y=0,ans,diff;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        y+=A[i];
    }
    ans=abs(x-y);

    for(int i=0;i<N;i++){
        x+=A[i];
        y-=A[i];
        if(ans>abs(x-y))ans=abs(x-y);
    }

    cout <<ans<<endl;
    
    return 0;

}
