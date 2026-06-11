#include <bits/stdc++.h>

using namespace std;

int N;
int num[102];
long long int a[102][22];

long long int dp(int d,int sum){
    if(sum > 20 || sum < 0) return 0;

    if(a[d][sum] >= 0) return a[d][sum];

    if(d == N-1){
        if(sum == num[N]){
            return a[d][sum] = 1;
        }else{
            return a[d][sum] = 0;
        }
    }

    long long int b = 0;
    int n = num[d+1]; 
    if(d ==0){
        b += dp(d+1 , sum + n);
    }else{
        b += dp(d+1 , sum + n) + dp(d+1 , sum - n);
        return a[d][sum] = b;
    }
}

int main(){
    fill_n(num,101,0);
    fill_n(*a,101*22,-1);

    cin >>N;
    for(int i = 1;i <= N;i++){
        cin >> num[i];
    }

    cout << dp(0,0) << endl;
}