#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int h,w; cin >> h >> w;
    long count = 0;
    

    if(h > 1 && w > 1){
        if(w%2==0){
            count = floor(h/2.0)*w/2+ceil(h/2.0)*w/2;
        }else{
            count = floor(h/2.0)*floor(w/2.0)+ceil(h/2.0)*ceil(w/2.0);
        }
    }else{
        count = 1;
    }

    printf("%ld",count);
}