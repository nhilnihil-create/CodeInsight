#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(){
    long long n;
    cin >> n;
    
    int a[] = {0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120};
    
    long long ans = 0;
    map<long long,int> mp;
    for(long long i = 2;i * i <= n;i++){
        if(n % i != 0)continue;
        n /= i;
        
        int ex = 1;
        while(n % i == 0){
            n /= i;
            ex++;
        }
        mp[i] += ex;
        
        int l = 1;
        while(mp[i] >= l){
            mp[i] -= l;
            l++;
        }
        ans += l-1;
    }
    if(n > 1){
        mp[n]++;
        for(int j = 0;j < 15;j++){
            if(a[j] <= mp[n] && mp[n] < a[j+1]){
                ans += j;
                mp[n] -= a[j];
                break;
            }
        }
    }
    
    cout << ans << endl;
}
