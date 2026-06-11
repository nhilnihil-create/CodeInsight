#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>



using namespace std;

long long int n,ans;

long long int f(long long int nn){
    long long int rec;
    if(nn/5 == 0) return 0;
    else{
        rec = nn/5 + f(nn/5);
    }
    return rec;
}

int main(){
    cin >> n;
    if(n % 2 == 1){
        ans = 0;
    }
    else{
        ans = f(n/2);
    }
    cout << ans << endl;
    return 0;
}