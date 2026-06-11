#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    scanf("%d",&n);
    cin>>s;
    int cnt = 0;
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(s[i] =='A' && s[i+1] == 'B' && s[i+2] == 'C')
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
