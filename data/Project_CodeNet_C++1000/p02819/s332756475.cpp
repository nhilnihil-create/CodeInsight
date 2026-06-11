#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int xx;
bool is_prime(ll x){
if(x<=1) return 0;
for(int i=2;i*i<=x;i++){
    if(x%i==0)return 0;
}
return 1;
}
int main(){
ll x;
cin>>x;
while(true){
    if(is_prime(x)){
        cout<< x << "\n";
        return 0;
    }
    x++;
}
return 0;

}

