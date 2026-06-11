#include <bits/stdc++.h>
using namespace std;
string n;
long long ans;
int main()
{
    cin>>n;
    int length=n.length();
    for(int i=0;i<length;i++){
        ans+=n[i]-'0';
    }
    if(ans%9)
        printf("No");
    else
        printf("Yes");
    return 0;
}
