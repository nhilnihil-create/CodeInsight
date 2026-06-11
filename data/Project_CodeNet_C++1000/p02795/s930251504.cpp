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

    int H,W,N,ans=0,m;

    cin >>H>>W>>N;

    m=max(H,W);

    int temp=0;
    while(temp<N){
        ans++;
        temp+=m;
    }
    
    cout << ans<<endl;
    return 0;
}