#include <bits/stdc++.h>

using namespace std;

#define MAX_A 25

int L;
int a[MAX_A];

int next_a(int x){
    int da[6];
    int max_x=0;
    int min_x=0;
    for(int i=0;i<L;i++){
        da[i] = x % 10;
        x /= 10;
    }
    sort(da,da+L);
    for(int i=0;i<L;i++){
        max_x = max_x * 10 +da[L-1-i];
        min_x = min_x * 10 + da[i];
    }
    return max_x - min_x;
}


int main (){
    
    while(1){
        cin >> a[0] >> L;
        if(a[0]==0 && L == 0)break;
        bool judge = false;
        int i,j;
        for(i=1;i<MAX_A;i++){
            a[i] = next_a(a[i-1]);
            for(j=0;j<i;j++){
                if(a[j] == a[i]){
                    judge = true;
                    break;
                }
            }
            if(judge)break;
        }
        cout << j << ' '<< a[i] << ' '<< i-j << endl;

    }
}
