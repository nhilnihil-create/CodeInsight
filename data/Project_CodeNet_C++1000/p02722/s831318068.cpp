#include<bits/stdc++.h>
using namespace std;

void testCase(){
    long long val, count = 0;
    cin>>val;
    if(val == 2) cout<<1<<endl;
    else{
        for(long long i = 2; i*i <= val; i++){
            if(val%i == 0){
                long long temp = val;
                while(temp%i == 0) temp = temp/i;
                if(temp%i == 1){
                    // cout<<i<<endl;
                    count++;
                }

                if(i != val/i){
                    temp = val;
                    long long j = val/i;
                    while(temp%j == 0) temp = temp/j;
                    if(temp%j == 1){
                        // cout<<val/j<<endl;
                        count++;
                    }
                }
                // count += 2;
            }
        }
        val--;
        count++;
        for(long long i = 2; i*i <= val; i++){
            if(val%i == 0){
                if(i*i == val){
                    // cout<<i<<endl;
                    count++;
                }
                else{
                    // cout<<i<<endl;
                    // cout<<val/i<<endl;
                    count += 2;
                }
            }
        }
        count++;
        cout<<count<<endl;
    }
}

int main(){
    int t;
    t = 1;
    // cin>>t;
    while(t--){
        testCase();
    }
}

