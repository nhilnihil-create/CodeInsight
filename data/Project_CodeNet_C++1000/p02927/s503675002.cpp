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

    int M,D,ans=0;
    cin>>M>>D;

    for(int m=1;m<=M;m++){
        for(int d=1;d<=D;d++){
            int m10=d/10;
            int m1=d%10;
            if(m==(m10*m1)&&m10>=2&&m1>=2)ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}