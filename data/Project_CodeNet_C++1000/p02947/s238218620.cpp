#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,i=0,j,c=0,p,m=1,max=0;
    string s[100000];
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s,s+n);
    for(i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            m++;
        }
        else
        {
            c+=(m*(m-1))/2;
            m=1;
        }
    }
    cout << c << endl;
    return 0;

}
