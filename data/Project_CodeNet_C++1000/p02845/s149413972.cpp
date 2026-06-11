#include<iostream>
using namespace std;

long long MOD = 1000000007;

int main(){
    //input
    long long N;
    cin >> N;
    long long A[N+1];
    long long i, j;
    for(j=1; j<=N; j++){
        cin >> A[j];
    }

    //calc
    long long ans=1;
    long long height[3];
    height[0]=-1;
    height[1]=-1;
    height[2]=-1;
    for(j=1; j<=N; j++){
        i = lower_bound(height,height+3,A[j])-height;
        i--;
        if(i<0){
            ans=0;
            break;
        }
        if(height[i]+1!=A[j]){
            ans=0;
            break;
        }
        if(i==2){
            if(height[2]==height[1]){
                if(height[1]==height[0]){
                    ans = (ans*3)%MOD;
                    height[2]++;
                }else{
                    ans = (ans*2)%MOD;
                    height[2]++;
                }
            }else{
                height[2]++;
            }
        }else if(i==1){
            if(height[1]==height[0]){
                ans = (ans*2)%MOD;
                height[1]++;
            }else{
                height[1]++;
            }
        }else if(i==0){
            height[0]++;
        }
    }

    //answer
    cout << ans << endl;
    system("pause");
    return 0;
}