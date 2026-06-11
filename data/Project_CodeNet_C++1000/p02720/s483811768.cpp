#include<iostream>
#include<queue>
typedef long long ll;
using namespace std;
int main()
{
    long K, ans, i;    cin >> K;
    std::queue<long> que;
    for(i=1; i<=9; i++){
        que.push(i);
    }
    while(i <= K){
        long x = que.front();
        que.pop();
        if(x%10 != 0){
            que.push(x*10 + x%10 - 1);
            i = i+1;
        }
        if(i > K)  break;
        que.push(x*10 + x%10);
        i = i+1;
        if(i > K)  break;  
        if(x%10 != 9){
            que.push(x*10 + x%10 + 1);
            i = i+1;
        }
    }
    if(K >= 9)  ans = que.back();
    else    ans = K;
    cout << ans;
}