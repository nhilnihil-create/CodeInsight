#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
    int k; cin>>k;
    if(k % 2 == 0){
        cout<<-1<<endl;
        return 0;
    }
    long long mod = k * (1e9 + 7);
    long long num = 7;
    for(int i = 1; i <= k; i++){
        if(num % k == 0){
            cout<<i<<endl;
            return 0;
        }
        num = (num * 10 + 7) % mod;
    }
    cout<<-1<<endl;
}
