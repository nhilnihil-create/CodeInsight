#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

long long int pow_num(int n, int p){
    long long int sum=1;
    rep(i, p) sum*=n;
    return sum;
}

int main(){
    int N;
    cin >> N;
    long long int A[N];
    long long int ans=1;
    int flag=0;
    rep(i, N){
        cin>>A[i];
        if(A[i] == 0){
            cout << "0" << endl;
            return 0;
        }
        int num_A=0;
        int num_ans=0;
        int A_sub=A[i];
        while(true){
            A_sub/=10;
            num_A++;
            if(A_sub < 10) break;
        }
        int ans_sub=ans;
        while(true){
            ans_sub/=10;
            num_ans++;
            if(ans_sub < 10) break;
        }

        if(1000000000000000000/ans < A[i]) {
            ans=-1;
            flag=1;
        }else if(num_A+num_ans > 17 && A_sub*ans_sub>=10){
            ans=-1;
            flag=1;
        }else if(ans*A[i] > pow_num(10, 18)){
            ans=-1;
            flag=1;
        }if(flag == 0) ans = A[i]*ans;
    }

    cout << ans << endl;
}