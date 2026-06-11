#include <bits/stdc++.h>

using namespace std;

int main(void){
    long long X;
    cin >> X;
    long long sum = 100;
    int ans;
    for(int i = 0; i < 5000; i++)
    {
        sum = sum + sum/100;
        if(sum >= X)
        {
            ans = i+1;
            break;
        }
    }
printf("%d\n",ans);
    
}