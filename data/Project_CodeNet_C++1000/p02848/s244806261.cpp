#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        int re=s[i];
        re=re+n;

        if(re>90 && (s[i]>='A' && s[i]<='Z'))
        {
            re=re-26;
        }
        char a=re;
        cout<<a;
    }
    return 0;


}
