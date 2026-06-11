#include<bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
int main(){

string s,t;
int flag=1;
long long sz,k,cnt=0;
cin >>s >> k;
sz = s.size();
long long l[sz],a=1;l[0]=1;
for (int i = 1; i < sz; ++i)
{
    if (s[i] == s[i-1])
    {
        l[i]=l[i-1]+1;
    }
    else {
        cnt+=l[i-1]/2;
        l[i]=1;
        flag = 0;
    }
    if (flag)
    {
       a++; 
    }
}

if (flag)
{
    cnt = sz*k/2;
    cout << cnt;
}
else{

    if (s[0]==s[sz-1])
    {
        cnt=cnt-a/2;
        cnt *=k;
        cnt=cnt+a/2+l[sz-1]/2 + (a+l[sz-1])/2*(k-1);
    }
    else{
        cnt+=l[sz-1]/2;
        cnt = cnt*k;
    }

    cout << cnt;
    
}
return 0;
}


