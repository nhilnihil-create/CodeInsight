#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,k,i=0,j,c=0,p=0,max=0,h[200010],q=0;
    string s[200100],a[200010];
    cin >> n;
    for(i=0;i<n;i++)
    {
        q=0;
        cin >> s[i];
    }
    sort(s,s+n);
    for(i=0;i<n;i++)
        {
            if(s[i]==s[i-1] && i!=0)
            {
                continue;
            }
        a[c]=s[i];
        c++;
        }
    sort(a,a+c);
    for(i=0;i<n;i++)
    {
        
        if(s[i]==s[i+1])
            {
                p++;
                if(max<p)
                {
                    max=p;
                }
            }
        else if(s[i]!=s[i+1])
        {
            h[q]=p;
            q++;
            p=0;
            
        }
    }
    for(i=0;i<c;i++)
    {
        if(h[i]==max)
        { 
            cout << a[i] << endl;
        }
    }
    
    return 0;

}
