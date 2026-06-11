#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if(n<=1)return false;
    for(int i=2;i<=1001000;i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    long long n;
    cin >> n;
    long long f[1001001];
    for(int i=0;i<1001001;i++)f[i]=0;

    long long a = n;
    long long ans = 0;

    for(int i=2;i<=1001000;i++){
        if(a%i==0){
            for(int j=1;;j++){
                f[i]++;
                a = a/i;
                if(a%i!=0)break;
            }
        }
    }

    for(int i=0;i<1001001;i++){
        for(int j=1;;j++){
            if(f[i]<j)break;
            else{
                ans++;
                f[i]-=j;
            }
        }
    }

    if(isPrime(a))ans++;

    cout << ans << endl;


}