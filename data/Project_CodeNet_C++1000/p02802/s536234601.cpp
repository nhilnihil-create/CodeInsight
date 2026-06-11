#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,c=0,a=0,i,p[100000];
    string s[100000]; 
    cin >> n >> m;
    bool mondai[1000000], f[1000000];
    for(i=0;i<m;i++)
    {
        cin >> p[i] >> s[i];
    }
    for(i=0;i<n;i++)
    {
        mondai[i]=false;
        f[i]=false;
    }
    for(i=0;i<m;i++)
    {
        if(s[i]=="AC")
        {
            f[p[i]]=true;
        }
    }
    for(i=0;i<m;i++)
    {
        if(mondai[p[i]]==false && f[p[i]]==true)
        {
            if(s[i]=="WA")
            {
                c++;
            }
            else if(s[i]=="AC")
            {
                a++;
                mondai[p[i]]=true;
            }
        }
    }
    cout << a << " " << c << endl;
 
}
