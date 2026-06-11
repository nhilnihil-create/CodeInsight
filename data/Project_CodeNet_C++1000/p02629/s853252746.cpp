#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    string s;
    while(n)
    {
        long long a=n%26;
        n=n/26;
        if(a==0)
        {
            n--;
            s+='z';
        }
        else
            s+=('a'+a-1);

    }
    reverse(s.begin(), s.end());

    cout<<s<<endl;
  return 0;
}
