#include<iostream>
using namespace std;
int main(){
    while(1){
        int N,sum,ans=0;
        cin >> N;
        if(N==0)    break;
        for(int i=1;i<N;i++){
            for(int j = i,sum = 0; sum <  N&&j<N; j++){
                sum += j;
                if(sum==N){
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}
