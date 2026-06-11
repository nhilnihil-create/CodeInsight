#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int main()
{
    string s;
    cin>>s;
    int ans = 0;
    int n = s.size();
    if(n == 1){
        ans = 0;
    }
    else{
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n-1-i]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
