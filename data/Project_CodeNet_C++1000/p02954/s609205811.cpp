#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
int main()
{
    int i,n,ans[100000]={0},cnt[2]={0,0},t;
    string s;
    cin >> s;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='L'){
            t=i;
            while(s[i]=='L'){
                cnt[i%2]++;
                i++;
            }
            ans[t-1]+=cnt[(t-1)%2];
            ans[t]+=cnt[t%2];
            cnt[0]=0;
            cnt[1]=0;
        }
        cnt[i%2]++;
    }
  	n=i-1;
    for(i=0;i<n;i++) cout << ans[i] << ' ';
    return 0;
}