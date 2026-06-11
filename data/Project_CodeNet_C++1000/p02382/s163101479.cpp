#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    int i;
    long x[100];
    long y[100];
    int p;
    double p2,p3;
    double ans0,ans1,ans2,ans_max;
    double temp1;
    
    cin >> n;
    
    for ( i = 0; i < n;++i ){
        cin >> x[i];
    }
    for ( i = 0; i < n;++i ){
        cin >> y[i];
    }
    
    /*
    cout << " "  << n << endl;
    
    for ( i = 0; i < n; ++i ){
        cout << " " << x[i];
    }
    cout << endl;
    
    for ( i = 0; i < n; ++i ){
        cout << " "<< y[i];
    }
    cout << endl;
    cout << endl;
    */

    ans0 = 0;
    ans1 = 0;
    ans2 = 0;
    ans_max = 0;
    temp1= 0;
    
    for ( i = 0; i < n; ++i ){
        temp1 = abs(x[i]-y[i]);
        if (ans_max < temp1)ans_max=temp1;
        ans0 = ans0 + temp1;
        ans1 = ans1 + pow(temp1,2);
        ans2 = ans2 + pow(temp1,3);
        //cout << endl;
    }
    
    p2 = 1.0 / 2.0;
    p3 = 1.0 / 3.0;
    
    ans1 = pow(ans1,p2);
    ans2 = pow(ans2,p3);
    
    //printf("%-20.6f\n",p2);
    //printf("%-20.6f\n",p3);
    printf("%-20.6f\n",ans0);
    printf("%-20.6f\n",ans1);
    printf("%-20.6f\n",ans2);
    printf("%-20.6f\n",ans_max);
    
    return 0;
}