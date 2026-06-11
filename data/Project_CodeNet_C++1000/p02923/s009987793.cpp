#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long N;
    cin >> N;

    long long max_count = 0;
    long long count = 0;
    long long H;
    for(int i=0; i<N; i++){
        long long H_tmp;
        cin >> H_tmp;
        if(i==0){H = H_tmp;continue;}

        if(H_tmp <= H){
            count +=1;
        }else{
            if(max_count < count){
                max_count = count;
            }
            count =0;
        }

        H = H_tmp;
    }

    if(max_count < count){
        max_count = count;
    }

    cout << max_count << endl;
    return 0;
}