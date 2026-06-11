#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


long long X,K,D;



int main(){

    cin >>X >> K >>D;

    long long tmp_cnt = 0;
 
    X = abs(X);

    //整数
    tmp_cnt = X/D;
    
    if(tmp_cnt >= K)
    {
        cout << abs(X-K*D);
        return 0;
    }else
    {
        long near_val = min(X-D*tmp_cnt, X -D*tmp_cnt - D) ;
        long next_near_val = max(X-D*tmp_cnt, X -D*tmp_cnt - D) ;
        long near_cnt = (X- near_val)/D;
        long rest_num = K- near_cnt;

        if(rest_num % 2 == 1)
        {
            cout << abs(next_near_val);
        }else
        {
            cout << abs(near_val);
        }
        
        return 0;

    }
    



    return  0;
}

