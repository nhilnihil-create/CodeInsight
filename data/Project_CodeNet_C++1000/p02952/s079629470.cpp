#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int main()
{
    int n;
    cin>>n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        string s = std::to_string(i);
        int len = s.size();
        if(len % 2 == 1){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
