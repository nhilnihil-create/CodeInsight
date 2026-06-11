#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n; cin >> n;

    if(fmod(n,1.08) == 0){
        int ans = n/1.08;
        printf("%d",ans);
    }else{
        //printf("もどした :%d\n",(int)floor(ceil(n/1.08)*1.08));
        if((int)floor(ceil(n/1.08)*1.08) == n){
            printf("%d",(int)ceil(n/1.08));
        }else{
            printf(":(");
        }

    }
}