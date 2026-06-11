#include <bits/stdc++.h>

using namespace std;
int n,cnt,ans;
string c;
int main()
{
    scanf("%d",&n);
    cin>>c;
    int len=c.length();
    for(int i=0;i<len;i++){
        if(c[i]=='W')
            cnt++;
    }
    for(int i=0;i<len;i++){
        if(c[i]=='W'&&i<len-cnt){
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
