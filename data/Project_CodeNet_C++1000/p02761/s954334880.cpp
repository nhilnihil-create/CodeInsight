#include<bits/stdc++.h>
using namespace std;
const int N=6;
int n,m,s[N],c[N]; 
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>s[i]>>c[i];
    for(int i=0;i<1000;i++){
        string t=to_string(i);
        if(t.size()==n){
            int j;for(j=1;j<=m;j++)if(t[s[j]-1]!=c[j]+'0')break;
            if(j==m+1){cout<<i<<endl;return 0;}
        }
    }
    return cout<<-1,0;
}
